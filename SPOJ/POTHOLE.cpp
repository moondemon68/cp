#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

template<typename T>
T dinic_flow(unordered_set<int>* adjlist, int* level, T** flow, T** capacity, int s, int t, T aug) {
    if (aug == 0 || s == t) return aug;
	T total_flow = 0;
    for (unordered_set<int>::iterator i = adjlist[s].begin(); aug != 0 && i != adjlist[s].end(); i++) {
        int next = *i;
		if (level[s] + 1 == level[next]) {
			T new_aug = capacity[s][next] - flow[s][next];
			T new_flow = dinic_flow(adjlist, level, flow, capacity, next, t, aug < 0 ? new_aug : min(aug, new_aug));
			total_flow += new_flow;
			flow[s][next] += new_flow;
			flow[next][s] -= new_flow;
			aug -= new_flow;
		}
	}
	return total_flow;
}
template<typename T>
T dinic(int n, vector<pair<int,T> >* adjlist, int s, int t) {
	T maxflow = 0;

	T** flow = new T*[n];
	T** capacity = new T*[n];
	unordered_set<int> *adj = new unordered_set<int>[n];
	for (int i = 0; i < n; i++) {
		flow[i] = new T[n];
		capacity[i] = new T[n];
		for (int j = 0; j < n; j++)
			flow[i][j] = 0, capacity[i][j] = 0;
		for (int j = 0; j < (int) adjlist[i].size(); j++) {
            adj[i].insert(adjlist[i][j].first);
            adj[adjlist[i][j].first].insert(i);
			capacity[i][adjlist[i][j].first] += adjlist[i][j].second;
		}
	}
	int* level = new int[n];

	while (1) {
		for (int i = 0; i < n; i++) level[i] = -1;
		level[s] = 0;
		queue<int> que; que.push(s);
		while (!que.empty()) {
			int t = que.front(); que.pop();
            for (unordered_set<int>::iterator it = adj[t].begin(); it != adj[t].end(); it++) {
				int next = *it;
				if (level[next] < 0 && flow[t][next] < capacity[t][next]) {
					level[next] = level[t] + 1;
					que.push(next);
				}
			}
		}
		if (level[t] < 0)
			break;
		T new_flow;
		while ((new_flow = dinic_flow(adj, level, flow, capacity, s, t, (T) -1)) > 0)
			maxflow += new_flow;
	}
	
	for (int i = 0; i < n; i++)
		delete [] flow[i], delete [] capacity[i];
	delete [] adj;
	delete [] flow;
	delete [] capacity;
	delete [] level;

	return maxflow;
}

int n;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<pair<int,long long> > adj[n+5];
        for (int i=1;i<n;i++) {
            int x;
            cin >> x;
            for (int j=1;j<=x;j++) {
                int y;
                cin >> y;
                if (i== 1|| y == n) adj[i-1].pb(mp(y-1,1));
                else adj[i-1].pb(mp(y-1,1e9));
            }
        }
        cout << dinic(n, adj, 0, n-1) << endl;
    }
	return 0;
}
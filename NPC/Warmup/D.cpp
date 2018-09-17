#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> adj[15];
	for (int i=1;i<n;i++) {
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i=0;i<n;i++) {
		//sort(adj[i].begin(),adj[i].end());
		reverse(adj[i].begin(),adj[i].end());
	}
	bool vis[15];
	memset (vis,0,sizeof(vis));
	stack<int> s;
	vis[0]=1;
	s.push(0);
	vector<int> ans;
	while (!s.empty()) {
		int cur=s.top();
		ans.push_back(cur);
		s.pop();
		for (int i=0;i<adj[cur].size();i++) {
			int next=adj[cur][i];
			if (!vis[next]) {
				vis[next]=1;
				s.push(next);
			}
		}
	}
	for (int i=0;i<ans.size();i++) {
		cout << ans[i];
		if (i!=ans.size()-1) cout << " ";
	}
	cout << endl;
	return 0;
}

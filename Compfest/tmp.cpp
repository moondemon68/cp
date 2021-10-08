#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= (int)(V).size(); pw *= 2, ++k) {
			jmp.emplace_back((int)(V).size() - pw * 2 + 1);
            for(int j = 0; j < ((int)(jmp[k]).size()); ++j)
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vector<int> time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vector<int>>& C) : time((int)(C).size()), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vector<int>>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> adj;
    for (int i=0;i<n;i++) {
        vector<int> v;
        adj.pb(v);
    }
    for (int i=0;i<n-1;i++) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    LCA lca = LCA(adj);

    int q;
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        if (lca.lca(x,y) == x) {
            cout << "TIDAK" << endl;
        } else {
            cout << "YA" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
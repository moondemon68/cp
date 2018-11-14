#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main () {
	int n,h,l;
	cin >> n >> h >> l;
	vector<int> adj[1005];
	for (int i=1;i<=h;i++) {
		int x;
		cin >> x;
		adj[n].push_back(x);
		adj[x].push_back(n);
	}
	for (int i=1;i<=l;i++) {
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int vis[1005];
	memset (vis,-1,sizeof(vis));
	queue<int> q;
	vis[n]=0;
	q.push(n);
	while (!q.empty()) {
		int cur=q.front();
		q.pop();
		for (int i=0;i<adj[cur].size();i++) {
			int next=adj[cur][i];
			if (vis[next]==-1) {
				vis[next]=vis[cur]+1;
				q.push(next);
			}
		}
	}
	for (int i=0;i<n;i++) {
		if (vis[i]==-1) vis[i]=MOD;
	}
	int ans=0,cntans=0;
	for (int i=0;i<n;i++) {
		if (vis[i]>cntans) {
			cntans=vis[i];
			ans=i;
		}
	}
	cout << ans << endl;
}

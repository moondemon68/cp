#include <bits/stdc++.h>

using namespace std;

int main () {
	int a[1005];
	for (int i=0;i<=1000;i++) a[i]=1000000007;
	int n,h,l;
	cin >> n >> h >> l;
	vector<int> adj[1005];
	for (int i=1;i<=h;i++) {
		int x;
		cin >> x;
		a[x]=0;
	}
	for (int i=1;i<=l;i++) {
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i=0;i<n;i++) {
		if (a[i]==0) continue;
		if (adj[i].empty()) continue;
		int worst=10000008;
		for (int j=0;j<adj[i].size();j++) {
			worst=min(worst,a[adj[i][j]]);
		}
		if (worst==10000008) continue;
		else a[i]=worst+1;
	}
	int ans=0,ansval=-1;
	for (int i=0;i<n;i++) {
		//cout << a[i] << " ";
		if (a[i]>ansval) {
			ansval=a[i];
			ans=i;
		}
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int k;
	cin >> k;
	cin.ignore();
	vector<int> adj[105];
	string s;
	int r=0,p=0;
	while (1>0) {
		string s;
		getline(cin,s);
		if (s=="-1") break;
		s+=' ';
		vector<int> a;
		int x=0;
		for (int i=0;i<s.size();i++) {
			if (s[i]==' ') {
				x/=10;
				a.push_back(x);
				x=0;
			} else {
				x+=s[i]-'0';
				x*=10;
			}
		}
		if (r==0) r=a[0];
		for (int i=1;i<a.size();i++) {
			adj[a[0]].push_back(a[i]);
			adj[a[i]].push_back(a[0]);
		}
	}
	p=r;
	int vis[105];
	memset (vis,0,sizeof(vis));
	queue<int> q;
	q.push(k);
	vis[k]=1;
	while (!q.empty()) {
		int cur=q.front();
		q.pop();
		for (int i=0;i<adj[cur].size();i++) {
			int next=adj[cur][i];
			if (vis[next]==0) {
				vis[next]=vis[cur]+1;
				if (vis[r]==0) q.push(next);
			}
		}
		if (vis[r]!=0) break;
	}
	vector<int> ans;
	for (int i=vis[r];i>=1;i--) {
		for (int j=0;j<adj[r].size();j++) {
			if (vis[adj[r][j]]==(i-1)) {
				ans.push_back(adj[r][j]);
				r=adj[r][j];
				break;
			}
		}
	}
	for (int i=ans.size()-1;i>=0;i--) {
		cout << ans[i] << " ";
	}
	cout << p << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int,int> x,pair<int,int> y) {
	return x.first>y.first;
}

int main () {
	int n,t;
	cin >> n >> t;
	pair<int,int> m[10005];
	memset (m,0,sizeof(m));
	for (int i=1;i<=n;i++) {
		cin >> m[i].first >> m[i].second;
	}
	sort (m+1,m+n+1,cmp);
	int ans=0,cur=t,pointer=0;
	//cout << "DEBUG" << endl;
	//for (int i=1;i<=n;i++) {
	//	cout << m[i].first << " " << m[i].second << endl;
	//}
	while (cur>=0) {
		int maxmoney=0;
		for (int i=1;i<=n;i++) {
			if (m[i].first>maxmoney&&m[i].second>=cur) {
				maxmoney=m[i].first;
				m[i].first=-1;
				break;
			}
		}
		ans+=maxmoney;
		cur--;
	}
	cout << ans << endl;
	return 0;
}

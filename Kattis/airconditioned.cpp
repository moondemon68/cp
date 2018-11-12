#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
	return a.second<b.second;
}

int main () {
	int n;
	cin >> n;
	pair<int,int> a[105];
	for (int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
	sort (a+1,a+n+1,cmp);
	int ans=1,temp=a[1].second;
	for (int i=2;i<=n;i++) {
		if (temp>=a[i].first&&temp<=a[i].second) continue;
		else {
			ans++;
			temp=a[i].second;
		}
	}
	cout << ans << endl;
	return 0;
}

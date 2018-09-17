#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[105];
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	int ans=0,cnt=0;
	for (int i=1;i<=n;i++) {
		if (a[i]==0) {
			cnt++;
			int p=cnt;
			for (int j=i+1;j<=n;j++) {
				if (a[j]==1) p++;
			}
			ans=max(p,ans);
		} else {
			int ct=0;
			for (int j=i;j<=n;j++) {
				if (a[j]==1) ct++;
				ans=max(ct,ans);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

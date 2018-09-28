#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[200005];
	for (int i=1;i<=n;i++) cin >> a[i];
	a[n+1]=-1;
	int ans=0,cnt=0;
	for (int i=1;i<=n;i++) {
		if (a[i+1]<=a[i]*2&&a[i+1]!=-1) {
			cnt++;
			continue;
		} else {
			ans=max(ans,cnt);
			cnt=0;
		}
	}
	cout << ans+1 << endl;
	return 0;
}

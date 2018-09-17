#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,k;
	cin >> n >> k;
	int a[100005];
	for (int i=1;i<=n;i++) cin >> a[i];
	bool y=1;
	for (int i=k;i<=n;i++) {
		if (a[i]!=a[k]) y=0;
	}
	if (y==0) {
		cout << -1 << endl;
		return 0;
	}
	int ans=0;
	for (int i=1;i<k;i++) {
		if (a[i]!=a[k]) ans=i;
	}
	cout << ans << endl;
	return 0;
}

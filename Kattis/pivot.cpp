#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[100005];
	for (int i=1;i<=n;i++) cin >> a[i];
	int ans=0;
	int b[100005],c[100005];
	b[1]=a[1];
	for (int i=2;i<=n;i++) {
		b[i]=max(a[i],b[i-1]);
	}
	c[n]=a[n];
	for (int i=n-1;i>=1;i--) {
		c[i]=min(a[i],c[i+1]);
	}
	for (int i=1;i<=n;i++) {
		if (b[i]==c[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}

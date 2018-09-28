#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int z=0,o=0,ans=0;
	cin >> z >> o;
	int a[25];
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n/2;i++) {
		//cout << a[i] << " " << a[n-i+1] << endl;
		if (a[i]>a[n-i+1]) swap(a[i],a[n-i+1]);
		if (a[i]==0&&a[n-i+1]==2) ans+=z;
		else if (a[i]==0&&a[n-i+1]==1) {
			cout << -1 << endl;
			return 0;
		} else if (a[i]==1&&a[n-i+1]==2) ans+=o; 
		else if (a[i]==1&&a[n-i+1]==0) {
			cout << -1 << endl;
			return 0;
		} else if (a[i]==2&&a[n-i+1]==2) ans+=min(o,z)*2;
	}
	if (n%2==1) {
		if (a[n/2+1]==2) ans+=min(o,z);
	}
	cout << ans << endl;
	return 0;
}

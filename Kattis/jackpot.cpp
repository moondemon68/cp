#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		long long ans=0;
		long long a[6];
		for (int i=1;i<=n;i++) {
			cin >> a[i];
		}
		bool out=0;
		for (int i=2;i<=n;i++) {
			a[i]=a[i]*a[i-1]/__gcd(a[i],a[i-1]);
			if (a[i]>1000000000) {
				out=1;
				break;
			}
		}
		if (out) cout << "More than a billion." << endl; else cout << a[n] << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[105];
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=2;i<=n;i++) {
		cout << a[1]/__gcd(a[i],a[1]) << "/" << a[i]/__gcd(a[i],a[1]) << endl;
	}
	return 0;
}

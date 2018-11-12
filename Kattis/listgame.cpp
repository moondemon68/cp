#include <bits/stdc++.h>

using namespace std;

int main () {
	int ans=0;
	int n;
	cin >> n;
	for (int i=2;i*i<=n;i++) {
		while (n%i==0) {
			n/=i;
			ans++;
		}
	}
	if (n!=1) ans++;
	cout << ans << endl;
	return 0;
}

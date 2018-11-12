#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		int a[1005];
		for (int i=1;i<=n;i++) cin >> a[i];
		int s=a[1];
		for (int i=2;i<=n;i++) {
			s++;
			if (s!=a[i]) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}

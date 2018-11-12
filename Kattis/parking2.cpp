#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		int a[25];
		int p=0,q=10000000;
		for (int i=1;i<=n;i++) {
			cin >> a[i];
			p=max(p,a[i]);
			q=min(q,a[i]);
		}
		cout << 2*(p-q) << endl;
	}
	return 0;
}

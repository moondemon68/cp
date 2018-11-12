#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int x,n;
		cin >> x >> n;
		cout << x << " " << n*(n+1)/2 << " " << n*(n+1)-n << " " << n*(n+1) << endl;
	}
	return 0;
}

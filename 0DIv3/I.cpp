#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	if (n<=3) cout << "NO" << endl;
	else if (n%4==0) {
		cout << "YES" << endl;
		cout << "1 * 2 = 2" << endl;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl;
		for (int i=1;i<n/4;i++) {
			cout << 4*i+1 << " - " << 4*i+2 << " = " << -1 << endl;
			cout << 4*i+4 << " - " << 4*i+3 << " = " << 1 << endl;
			cout << "-1 + 1 = 0" << endl;
			cout << "24 + 0 = 24" << endl;
		}
	} else if (n%4==2) {
		cout << "YES" << endl;
		cout << "1 * 2 = 2" << endl;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl;
		for (int i=1;i<=n/4-1;i++) {
			cout << 4*i+1 << " - " << 4*i+2 << " = " << -1 << endl;
			cout << 4*i+4 << " - " << 4*i+3 << " = " << 1 << endl;
			cout << "-1 + 1 = 0" << endl;
			cout << "24 + 0 = 24" << endl;
		}
		cout << n << " - " << n-1 << " = " << 1 << endl;
		cout << "24 * 1 = 24" << endl;
	} else if (n==5) {
		cout << "YES" << endl;
		cout << "1 + 5 = 6" << endl;
		cout << "3 * 4 = 12" << endl;
		cout << "6 * 2 = 12" << endl;
		cout << "12 + 12 = 24" << endl;
	} else if (n%4==1||n%4==3) {
		cout << "YES" << endl;
		cout << "1 + 5 = 6" << endl;
		cout << "3 * 4 = 12" << endl;
		cout << "6 * 2 = 12" << endl;
		cout << "12 + 12 = 24" << endl;
		for (int i=6;i<=n;i+=2) {
			cout << i+1 << " - " << i << " = " << 1 << endl;
			cout << "24 * 1 = 24" << endl;
		}
	}
	
	return 0;
}

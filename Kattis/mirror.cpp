#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		cout << "Test " << t << endl;
		char a[25][25];
		int r,c;
		cin >> r >> c;
		for (int i=1;i<=r;i++) {
			string s;
			cin >> s;
			for (int j=1;j<=c;j++) {
				a[i][j]=s[j-1];
			}
		}
		for (int i=r;i>=1;i--) {
			for (int j=c;j>=1;j--) {
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

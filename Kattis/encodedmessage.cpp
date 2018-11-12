#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		string s;
		cin >> s;
		int a=s.size();
		int b=sqrt(a);
		char c[105][105];
		int p=0;
		for (int i=1;i<=b;i++) {
			for (int j=1;j<=b;j++) {
				c[i][j]=s[p];
				p++;
			}
		}
		for (int i=b;i>=1;i--) {
			for (int j=1;j<=b;j++) {
				cout << c[j][i];
			}
		}
		cout << endl;
	}
	return 0;
}

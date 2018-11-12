#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		string s;
		cin >> s;
		char a[105][105];
		int n=ceil(sqrt(s.size())),p=0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (p<s.size()) a[i][j]=s[p];
				else a[i][j]='*';
				p++;
			}
		}
		for (int j=1;j<=n;j++) {
			for (int i=n;i>=1;i--) {
				if (a[i][j]=='*') continue;
				else cout << a[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}

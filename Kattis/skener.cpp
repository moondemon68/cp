#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	char x[55][55];
	for (int i=1;i<=a;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=b;j++) {
			x[i][j]=s[j-1];
		}
	}
	for (int i=1;i<=a;i++) {
		for (int l=1;l<=c;l++) {
			for (int j=1;j<=b;j++) {
				for (int k=1;k<=d;k++) cout << x[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int r,c;
	cin >> r >> c;
	char a[55][55];
	for (int i=1;i<=r;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=c;j++) {
			a[i][j]=s[j-1];
		}
	}
	int one=0,two=0,three=0,four=0,zero=0;
	for (int i=1;i<r;i++) {
		for (int j=1;j<c;j++) {
			int cnt=0;
			if (a[i][j]=='#'||a[i+1][j]=='#'||a[i][j+1]=='#'||a[i+1][j+1]=='#') continue;
			if (a[i][j]=='X') cnt++;
			if (a[i+1][j]=='X') cnt++;
			if (a[i][j+1]=='X') cnt++;
			if (a[i+1][j+1]=='X') cnt++;
			if (cnt==0) zero++;
			if (cnt==1) one++;
			if (cnt==2) two++;
			if (cnt==3) three++;
			if (cnt==4) four++;
		}
	}
	cout << zero << endl << one << endl << two << endl << three << endl << four << endl;
	return 0;
}

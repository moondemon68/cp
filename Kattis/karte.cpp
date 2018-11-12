#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int a[5][14];
	memset (a,0,sizeof(a));
	for (int i=0;i<s.size();i+=3) {
		int r,c=0;
		if (s[i]=='P') r=1; else if (s[i]=='K') r=2; else if (s[i]=='H') r=3; else r=4;
		c+=(s[i+1]-'0')*10+(s[i+2]-'0');
		a[r][c]++;
		if (a[r][c]>1) {
			cout << "GRESKA" << endl;
			return 0;
		}
	}
	for (int i=1;i<=4;i++) {
		int cnt=0;
		for (int j=1;j<=13;j++) {
			if (a[i][j]==0) cnt++;
		}
		cout << cnt << " ";
	}
	return 0;
}

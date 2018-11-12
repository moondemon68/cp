#include <bits/stdc++.h>

using namespace std;

char a[10][10];

bool check(int x, int y) {
	for (int i=1;i<=8;i++) {
		if (i==x) continue;
		if (a[i][y]=='*') return 0; 
	}
	for (int i=1;i<=8;i++) {
		if (i==y) continue;
		if (a[x][i]=='*') return 0; 
	}
	for (int i=-8;i<=8;i++) {
		if (i==0) continue;
		if (x+i>8||y+i>8||x+i<1||y+i<1) continue;
		if (a[x+i][y+i]=='*') return 0;
	}
	int num=x+y,cnt=0;
	for (int i=1;i<num;i++) {
		if (i>8||num-i>8||i<1||num-i<1) continue;
		if (a[i][num-i]=='*') cnt++;
	}
	if (cnt>1) return 0;
	return 1;
}

int main () {
	memset (a,'x',sizeof(a));
	for (int i=1;i<=8;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=8;j++) {
			a[i][j]=s[j-1];
		}
	}
	/*for (int i=1;i<=8;i++) {
		for (int j=1;j<=8;j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	bool valid=1;
	int cnt=0;
	for (int i=1;i<=8;i++) {
		for (int j=1;j<=8;j++) {
			if (a[i][j]=='*') {
				cnt++;
				if (!check(i,j)) valid=0;
			}
		}
	}
	if (valid&&cnt==8) cout << "valid" << endl; else cout << "invalid" << endl;
	return 0;
}

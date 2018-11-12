#include <bits/stdc++.h>

using namespace std;

int main () {
	int r,c;
	cin >> r >> c;
	char a[205][205];
	for (int i=1;i<=r;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=c;j++) {
			a[i][j]=s[j-1];
		}
	}
	int ans=0,cnt=0,x=1,y=1,out=0;
	while (cnt<100000&&a[x][y]!='T') {
		ans++;
		cnt++;
		if (a[x][y]=='E') {
			y++;
			if (y>c) {
				out=1;
				break;
			}
		}
		else if (a[x][y]=='W') {
			y--;
			if (y<1) {
				out=1;
				break;
			}
		}
		else if (a[x][y]=='N') {
			x--;
			if (x<1) {
				out=1;
				break;
			}
		}
		else if (a[x][y]=='S') {
			x++;
			if (x>r) {
				out=1;
				break;
			}
		}
	}
	if (out) cout << "Out" <<endl;
	else if (cnt<50000) cout << ans << endl; else cout << "Lost" << endl;
	return 0;
}

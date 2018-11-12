#include <bits/stdc++.h>

using namespace std;

int main () {
	int r,c,k;
	cin >> r  >> c >> k;
	char a[105][105];
	for (int i=1;i<=r;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=c;j++) {
			a[i][j]=s[j-1];
		}
	}
	int ma=0,msr=0,msc=0;
	for (int sr=1;sr<=r-k+1;sr++) {
		for (int sc=1;sc<=c-k+1;sc++) {
			int cnt=0;
			for (int pr=sr+1;pr<sr+k-1;pr++) {
				for (int pc=sc+1;pc<sc+k-1;pc++) {
					if (a[pr][pc]=='*') cnt++;
				}
			}
			//cout << cnt;
			if (cnt>ma) {
				ma=cnt;
				msr=sr;
				msc=sc;
			}
		}
	}
	cout << ma << endl;
	a[msr][msc]='+';
	a[msr][msc+k-1]='+';
	a[msr+k-1][msc]='+';
	a[msr+k-1][msc+k-1]='+';
	for (int i=msr+1;i<msr+k-1;i++) {
		a[i][msc]='|';
		a[i][msc+k-1]='|';
	}
	for (int i=msc+1;i<msc+k-1;i++) {
		a[msr][i]='-';
		a[msr+k-1][i]='-';
	}
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}

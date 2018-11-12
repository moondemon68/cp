#include <bits/stdc++.h>

using namespace std;

int main() {
	char a[10][10];
	for (int i=1;i<=5;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=5;j++) {
			a[i][j]=s[j-1];
		}
	}
	bool r=1;
	int cnt=0;
	int x[]={1,2,2,1,-1,-2,-2,-1};
	int y[]={2,1,-1,-2,-2,-1,1,2};
	for (int i=1;i<=5;i++) {
		for (int j=1;j<=5;j++) {
			if (a[i][j]=='k') {
				cnt++;
				for (int k=0;k<8;k++) {
					int p=i+x[k],q=j+y[k];
					if (p>=1&&p<=5&&q>=1&&q<=5) {
						if (a[p][q]=='k') r=0; 
					}
				}
			}
		}
	}
	if (cnt==9&&r) cout << "valid"; else cout << "invalid";
	return 0;
}

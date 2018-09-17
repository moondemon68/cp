#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,ans=0;
	cin >> n;
	string s;
	cin >> s;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			int u=0,d=0,l=0,r=0;
			for (int k=i;k<=j;k++) {
				if (s[k]=='U') u++;
				if (s[k]=='D') d++;
				if (s[k]=='L') l++;
				if (s[k]=='R') r++;
			}
			if ((u==d)&&(l==r)) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	string a,b,c;
	a=""; 
	b="";
	c="";
	for (int i=1;i<=1000;i+=3) {
		a+="ABC";
	}
	for (int i=1;i<=1000;i+=4) {
		b+="BABC";
	}
	for (int i=1;i<=1000;i+=6) {
		c+="CCAABB";
	}
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnta=0,cntb=0,cntc=0;
	for (int i=0;i<n;i++) {
		if (s[i]==a[i]) cnta++;
		if (s[i]==b[i]) cntb++;
		if (s[i]==c[i]) cntc++;
	}
	int ans=max(cnta,max(cntb,cntc));
	cout << ans << endl;
	if (cnta==ans) cout << "Adrian" << endl;
	if (cntb==ans) cout << "Bruno" << endl;
	if (cntc==ans) cout << "Goran" << endl;
	return 0;
} 

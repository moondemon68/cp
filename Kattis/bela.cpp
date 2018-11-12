#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	char s;
	cin >> n >> s;
	int ans=0;
	for (int i=1;i<=4*n;i++) {
		string x;
		cin >> x;
		if (x[0]=='A') if (x[1]==s) ans+=11; else ans+=11;
		if (x[0]=='K') if (x[1]==s) ans+=4; else ans+=4;
		if (x[0]=='Q') if (x[1]==s) ans+=3; else ans+=3;
		if (x[0]=='J') if (x[1]==s) ans+=20; else ans+=2;
		if (x[0]=='T') if (x[1]==s) ans+=10; else ans+=10;
		if (x[0]=='9') if (x[1]==s) ans+=14; else ans+=0;
	}
	cout << ans << endl;
	return 0;
}

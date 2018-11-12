#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int b=0,w=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='B') b++; else w++;
	}
	if (b==w) cout << 1 << endl; else cout << 0 << endl;
	return 0;
}

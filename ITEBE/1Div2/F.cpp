#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int x=0,y=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='x') x++; else y++;
	}
	if (x>y) {
		for (int i=1;i<=x-y;i++) {
			cout << 'x';
		}
	}
	else {
		for (int i=1;i<=y-x;i++) {
			cout << 'y';
		}
	}
	return 0;
}

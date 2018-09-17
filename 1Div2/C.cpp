#include <bits/stdc++.h>

using namespace std;

bool valid(string s) {
	for (int i=0;i<s.size()-1;i++) {
		if (s[i]=='1'&&s[i+1]=='1') return 0;
	}
	return 1;
}

int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool y=1;
	if (!valid(s)) y=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='0') {
			s[i]='1';
			if (valid(s)) y=0;
			s[i]='0';
		}
	}
	if (y) cout << "YES";
	else cout << "NO";
}

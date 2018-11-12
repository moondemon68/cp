#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	s+="XXXX";
	for (int i=0;i<s.size();i++) {
		if (s[i]=='X') return 0;
		if (s[i]=='R'&&s[i+1]=='L'&&s[i+2]=='B') {
			cout << 'C';
			i+=2;
		}
		else if (s[i]=='R'&&s[i+1]=='B'&&s[i+2]=='L') {
			cout << 'C';
			i+=2;
		}
		else if (s[i]=='B'&&s[i+1]=='L'&&s[i+2]=='R') {
			cout << 'C';
			i+=2;
		}
		else if (s[i]=='B'&&s[i+1]=='R'&&s[i+2]=='L') {
			cout << 'C';
			i+=2;
		}
		else if (s[i]=='L'&&s[i+1]=='R'&&s[i+2]=='B') {
			cout << 'C';
			i+=2;
		}
		else if (s[i]=='L'&&s[i+1]=='B'&&s[i+2]=='R') {
			cout << 'C';
			i+=2;
		}
		else if (s[i]=='L') cout << 'H';
		else if (s[i]=='R') cout << 'S';
		else if (s[i]=='B') cout << 'K';
	}
	return 0;
}

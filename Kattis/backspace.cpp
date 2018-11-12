#include <bits/stdc++.h>

using namespace std;

int main () {
	stack<char> a;
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='<') a.pop();
		else a.push(s[i]);
	}
	s="";
	while (!a.empty()) {
		s+=a.top();
		a.pop();
	}
	for (int i=s.size()-1;i>=0;i--) {
		cout << s[i];
	}
	return 0;
}

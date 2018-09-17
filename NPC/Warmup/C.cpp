#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		string s;
		cin >> s;
		s+='/';
		int n=0;
		for (int i=0;i<s.size()-1;i++) {
			if (s[i]=='/') continue;
			if (s[i+1]=='/') {
				n+=s[i]-'0';
				cout << char(n+'a'-1);
				n=0;
			}
			else {
				n+=s[i]-'0';
				n*=2;
			}
		}
		cout << endl;
	}
}

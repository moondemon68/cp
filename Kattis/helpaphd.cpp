#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		string s;
		cin >> s;
		if (s=="P=NP") cout << "skipped" << endl;
		else {
			bool y=0;
			int a=0,b=0;
			for (int i=0;i<s.size();i++) {
				if (s[i]=='+') {
					y=1;
					continue;
				}
				if (!y) {
					a*=10;
					a+=s[i]-'0';
				} else {
					b*=10;
					b+=s[i]-'0';
				}
			}
			cout << a+b << endl;
		}
	}
	return 0;
}

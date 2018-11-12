#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	cin.ignore();
	for (int t=1;t<=tc;t++) {
		string s;
		getline(cin,s);
		if (s.size()<11) {
			cout << endl;
			continue;
		}
		if (s[0]=='s'&&s[1]=='i'&&s[2]=='m'&&s[3]=='o'&&s[4]=='n'&&s[5]==' '&&
		s[6]=='s'&&s[7]=='a'&&s[8]=='y'&&s[9]=='s'&&s[10]==' ') {
			for (int i=11;i<s.size();i++) {
				cout << s[i];
			}
		}
		cout << endl;
	}
}

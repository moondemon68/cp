#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	getline(cin,s);
	long long n;
	cin >> n;
	s+='*';
	long long x=0;
	for (int i=0;i<s.size();i++) {
		//cout << s[i] << " ";
		if (s[i]==' '||s[i]=='*') {
			x/=10;
			//cout << x << endl;
			if (x==n) {
				cout << "ADA" << endl;
				return 0;
			}
			x=0;
		} else {
			x+=s[i]-'0';
			//cout << s[i] << " " << x << endl;
			x*=10;
		}
	}
	cout << "TIDAK ADA" << endl;
	return 0;
}

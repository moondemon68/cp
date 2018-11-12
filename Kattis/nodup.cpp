#include <bits/stdc++.h>

using namespace std;

vector<string> a;

bool check(string s) {
	if (a.empty()) a.push_back(s);
	else {
		for (int i=0;i<a.size();i++) {
			if (s==a[i]) return 0;
		}
	}
	a.push_back(s);
	return 1;
}
int main () {
	string s;
	getline(cin,s);
	string x="";
	for (int p=0;p<s.size();p++) {
		if (p==s.size()-1||s[p+1]==' ') {
			x+=s[p];
			if (!check(x)) {
				cout << "no" << endl;
				return 0;
			}
			x="";
			p++;
		} else x+=s[p];
	}
	cout << "yes" << endl;
	return 0;
}

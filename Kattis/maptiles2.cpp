#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	cout << s.size() << " ";
	int x=0,y=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='1') x+=pow(2,s.size()-1-i); 
		if (s[i]=='2') y+=pow(2,s.size()-1-i); 
		if (s[i]=='3') {
			x+=pow(2,s.size()-1-i); 
			y+=pow(2,s.size()-1-i); 
		}
	}
	cout << x << ' ' << y;
	return 0;
}

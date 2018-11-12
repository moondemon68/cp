#include <bits/stdc++.h>

using namespace std;

int main () {
	int p[4];
	cin >> p[1] >> p[2] >> p[3];
	sort (p+1,p+4);
	int a=p[1],b=p[2],c=p[3];
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='A') cout << a << " ";
		else if (s[i]=='B') cout << b << " ";
		else cout << c << " ";
	}
	return 0;
}

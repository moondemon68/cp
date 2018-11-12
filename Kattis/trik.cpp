#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int a[3]={1,0,0};
	for (int i=0;i<s.size();i++) {
		if (s[i]=='A') swap(a[0],a[1]);
		if (s[i]=='B') swap(a[1],a[2]);
		if (s[i]=='C') swap(a[0],a[2]);
	}
	for (int i=0;i<=2;i++) {
		if (a[i]==1) cout << i+1 << endl;
	}
	return 0;
}

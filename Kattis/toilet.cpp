#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	cin >> s;
	int ans=0;
	for (int i=1;i<s.size();i++) {
		if (s[i]=='D') ans+=2;
	}
	if (s[0]=='D') ans--;
	cout << ans << endl;
	ans=0;
	for (int i=1;i<s.size();i++) {
		if (s[i]=='U') ans+=2;
	}
	if (s[0]=='U') ans--;
	cout << ans << endl;
	ans=0;
	for (int i=1;i<s.size();i++) {
		if (s[i]!=s[i-1]) ans++;
	}
	cout << ans << endl;
	return 0;
}

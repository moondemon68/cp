#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	int n;
	while (cin >> n) {
		if (n==0) return 0;
		cin >> s;
		string c="ABCDEFGHIJKLMNOPQRSTUVWXYZ_.ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
		string ans="";
		for (int i=0;i<s.size();i++) {
			for (int j=0;j<c.size();j++) {
				if (s[i]==c[j]) {
					ans+=c[j+n];
					break;
				}
			}
		}
		for (int i=ans.size()-1;i>=0;i--) cout << ans[i];
		cout << endl;
	}
	return 0;
}

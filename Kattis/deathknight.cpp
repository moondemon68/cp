#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ans=0;
	for (int t=1;t<=n;t++) {
		string s;
		cin >> s;
		bool y=0;
		for (int i=0;i<s.size()-1;i++) {
			if (s[i]=='C'&&s[i+1]=='D') y=1;
		}
		if (!y) ans++;
	}
	cout << ans << endl;
	return 0;
}

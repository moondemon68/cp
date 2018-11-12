#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	while (cin >> s) {
		int n=0;
		for (int i=2;i<s.size();i++) {
			n*=10;
			n+=s[i]-'0';
		}
		n*=n;
		int ans=0;
		for (int i=1;i<=sqrt(n);i++) {
			if (n%i==0) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

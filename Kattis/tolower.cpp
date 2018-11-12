#include <bits/stdc++.h>

using namespace std;

int main () {
	int p,t,ans=0;;
	cin >> p >> t;
	for (int i=1;i<=p;i++) {
		bool y=1;
		for (int j=1;j<=t;j++) {
			string s;
			cin >> s;
			bool x=1;
			for (int k=0;k<s.size();k++) {
				if (k==0) continue;
				else {
					if (s[k]>='A'&&s[k]<='Z') x=0;
				}
			}
			if (!x) y=0;
		}
		if (y) ans++;
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	vector<string> a;
	while (cin >> s) {
		string t=s;
		for (int i=0;i<s.size();i++) {
			if (s[i]>='A'&&s[i]<='Z') s[i]+=32;
		}
		bool y=0;
		for (int i=0;i<a.size();i++) {
			if (s==a[i]) {
				y=1;
				break;
			} 
		}
		if (y) cout << " . "; else {
			a.push_back(s);
			cout << t << ' ';
		}
	}
}

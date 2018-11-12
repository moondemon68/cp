#include <bits/stdc++.h>

using namespace std;

int main () {
	vector<string> a;
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		string p,q;
		cin >> p >> q;
		if (a.empty()) {
			a.push_back(p);
			cout << p << ' ' << q  << endl;
		} else {
			bool y=0;
			for (int j=0;j<a.size();j++) {
				if (a[j]==p) y=1;
			}
			if (!y) {
				a.push_back(p);
				cout << p << ' ' << q  << endl;
			}
		}
		if (a.size()==12) return 0;
	}
	return 0;
}

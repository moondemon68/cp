#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		set<string> a;
		for (int i=1;i<=n;i++) {
			string b,c;
			cin >> b >> c;
			a.insert(b);
			a.insert(c);
			cout << a.size() << endl;
		}
	}
	return 0;
}

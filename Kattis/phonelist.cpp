#include <bits/stdc++.h>

using namespace std;

bool check(string a,string b) {
	for (int i=0;i<a.size();i++) {
		if (a[i]!=b[i]) return 0;
	}
	return 1;
}

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		vector<string> b[11];
		for (int i=1;i<=n;i++) {
			string s;
			cin >> s;
			b[s.size()].push_back(s);
		}
		bool y=1;
		for (int i=1;i<10;i++) {
			for (int j=0;j<b[i].size();j++) {
				for (int k=i+1;k<=10;k++) {
					for (int l=0;l<b[k].size();l++) {
						if (check(b[i][j],b[k][l])) {
							y=0;
							break;
						}
					}
					if (!y) break;
				}
				if (!y) break;
			}
			if (!y) break;
		}
		if (y) cout << "YES" << endl; else cout << "NO" << endl;
	}
	return 0;
}

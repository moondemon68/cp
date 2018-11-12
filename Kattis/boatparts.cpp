#include <bits/stdc++.h>

using namespace std;

int main () {
	int p,n;
	cin >> p >> n;
	vector<string> a;
	for (int i=1;i<=n;i++) {
		string s;
		cin >> s;
		bool y=0;
		for (int j=0;j<a.size();j++) {
			if (a[j]==s) y=1;
		}
		if (!y) a.push_back(s);
		if (a.size()==p) {
			cout << i << endl;
			return 0;
		} 
	}
	cout << "paradox avoided" << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	n%=2;
	string a,b;
	cin >> a >> b;
	if (n==0) {
		if (a==b) cout << "Deletion succeeded" << endl; else cout << "Deletion failed" << endl;
	} else {
		bool y=1;
		for (int i=0;i<a.size();i++) {
			if (a[i]==b[i]) y=0;
		}
		if (y) cout << "Deletion succeeded" << endl; else cout << "Deletion failed" << endl;
	}
	return 0;
}

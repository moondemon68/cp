#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		string a,b;
		cin >> a >> b;
		cout << a << endl << b << endl;
		for (int i=0;i<a.size();i++) {
			if (a[i]==b[i]) cout << "."; else cout << "*";
		}
		cout << endl << endl;
	}
	return 0;
}

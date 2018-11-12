#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int a,b,c;
		cin >> a >> b >> c;
		bool y=0;
		if (a*b==c||a*c==b||b*c==a||a+b==c||a+c==b||b+c==a) y=1;
		if (y) cout << "Possible" << endl; else cout << "Impossible" << endl;
	}
	return 0;
}

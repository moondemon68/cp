#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		double b,p;
		cin >> b >> p;
		cout << fixed << setprecision(4) << 60*(b-1)/p << " " << 60*b/p  << " " << 60*(b+1)/p << endl;
	}
	return 0;
}

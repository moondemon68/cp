#include <bits/stdc++.h>

using namespace std;

int main () {
	double d,v;
	while (1>0) {
		cin >> d >> v;
		if (d==0) return 0;
		cout << fixed << setprecision(8) << cbrt((d*d*d)-v*6/acos(-1)) << endl;
	}
	return 0;
}

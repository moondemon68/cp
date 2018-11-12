#include <bits/stdc++.h>

using namespace std;

int main () {
	double d,v;
	while (1>0) {
		cin >> d >> v;
		if (d==0) return 0;
		cout << fixed << setprecision(7) << cbrt(4/acos(-1)*(acos(-1)*d*d*d/4-v)) << endl;
	}
	return 0;
}

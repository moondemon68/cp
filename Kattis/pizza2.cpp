#include <bits/stdc++.h>

using namespace std;

int main () {
	double c,r;
	cin >> r >> c;
	c=r-c;
	cout << fixed << setprecision(8) << (acos(-1)*c*c*100/(r*acos(-1)*r)) << endl;
	return 0;
}

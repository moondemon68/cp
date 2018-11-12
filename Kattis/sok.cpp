#include <bits/stdc++.h>

using namespace std;

int main () {
	double a,b,c,i,j,k;
	cin >> a >> b >> c >> i >> j >> k;
	double x=a/i;
	x=min(x,b/j);
	x=min(x,c/k);
	cout << fixed << setprecision(6) << a-i*x << " " << b-j*x << " " << c-k*x;
	return 0;
}

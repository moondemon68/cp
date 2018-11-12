#include <bits/stdc++.h>

using namespace std;

int main () {
	double a,b,s,m,n;
	while (cin >> a >> b >> s >> m >> n) {
		if (a==0) return 0;
		double x=atan((b*n)/(a*m));
		cout << fixed << setprecision(2) << x*180/acos(-1) << " " << (cos(x)*a*m+sin(x)*b*n)/s<< endl;
	}
	return 0;
}

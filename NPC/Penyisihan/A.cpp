#include <bits/stdc++.h>

using namespace std;

double y(double n,double a) {
	return (1+sqrt(1+4*(n)*a*a))/(2*a*a);
}

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int m,n;
		cin >> m >> n;
		double a[15];
		for (int i=1;i<=m;i++) cin >> a[i];
		for (int i=1;i<=m;i++) cout << i*y(n,a[i]) << endl;
	}
	
	return 0;
}

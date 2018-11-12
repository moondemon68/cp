#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int n=1;n<=tc;n++) {
		double v,a,x,h1,h2,g=9.81;
		cin >> v >> a >> x >> h1 >> h2;
		double t=x/(v*cos(a*acos(-1)/180));
		double pass=v*t*sin(a*acos(-1)/180)-0.5*g*t*t;
		if (pass-1>=h1&&pass+1<=h2) cout << "Safe" << endl; else cout << "Not Safe" << endl;
	}
	return 0;
}

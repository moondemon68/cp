#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		double x,y;
		cin >> x >> y;
		double h=(x+y+sqrt(x*x-x*y+y*y))/6;
		cout <<fixed << setprecision(6)<< (x-2*h)*(y-2*h)*h << endl;
	}
	return 0;
}

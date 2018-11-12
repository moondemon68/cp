#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		double x[105],y[105];
		int n;
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> x[i] >> y[i];
		}
		double area=0;
		for (int i=1;i<n;i++) {
			area+=x[i]*y[i+1]-y[i]*x[i+1];
		}
		area+=x[n]*y[1]-y[n]*x[1];
		area/=2;
		cout << area << endl;
	}
	return 0;
}

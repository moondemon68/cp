#include <bits/stdc++.h>

using namespace std;

int main () {
	double c,ans=0;
	cin >> c;
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		double w,l;
		cin >> w >> l;
		ans+=w*l*c;
	}
	cout << fixed << setprecision(8) << ans << endl;
	return 0;
}

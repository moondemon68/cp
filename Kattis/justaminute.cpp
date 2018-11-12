#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	double cnt=0;
	double ans=0;
	for (int i=1;i<=n;i++) {
		double x,y;
		cin >> x >> y;
		cnt+=x;
		ans+=y;
	}
	double p=(double)ans/(double)cnt;
	p=(double)p/(double)60;
	if (p>1)cout <<fixed << setprecision(8) << p << endl; else cout << "measurement error" << endl;
	return 0;
}

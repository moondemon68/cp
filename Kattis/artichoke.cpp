#include <bits/stdc++.h>

using namespace std;

int main () {
	double p,a,b,c,d;
	int n;
	cin >> p >> a >> b >> c >> d >> n;
	double maxi=0,mini=100000000,ans=0;
	for (int i=1;i<=n;i++) {
		double x=p*(sin(a*i+b)+cos(c*i+d)+2);
		if (x>maxi) {
			maxi=x;
			mini=x;
		}
		maxi=max(maxi,x);
		mini=min(mini,x);
		ans=max(ans,maxi-mini);
	}
	cout << fixed << setprecision(6) << ans << endl;
}

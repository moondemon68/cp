#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,h,a,b,k;
	cin >> n >> h >> a >> b >> k;
	for (int t=1;t<=k;t++) {
		int ta,fa,tb,fb;
		cin >> ta >> fa >> tb >> fb;
		int dt=abs(ta-tb);
		int ans=dt;
		if (dt==0) ans+=abs(fa-fb);
		if (dt>0) {
			if (fa<=a&&fb<=a) ans+=a-fa+a-fb;
			else if (fa>=b&&fb>=b) ans+=fa-b+fb-b;
			else ans+=abs(fa-fb);
		}
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n;
	while (cin >> n) {
		long long ans=0;
		for (int i=1;i*i<=n;i++) {
			if (i*i==n) {
				ans+=i;
				continue;
			}
			if (n%i==0) {
				ans+=i;
				if (n/i==n) continue;
				ans=ans+(n/i);
			}
		}
		//cout << ans << " ";
		if (ans==n) cout << n << " perfect" << endl;
		else if (abs(ans-n)<=2) cout << n << " almost perfect" << endl;
		else cout << n << " not perfect" << endl;
	}
	return 0;
}

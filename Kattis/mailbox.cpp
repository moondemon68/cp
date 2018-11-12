#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int k,n;
		cin >> k >> n;
		int h=n;
		int ans=0;
		while (k>1) {
			ans+=h;
			k--;
			int m=(h/2+h)/2;
			ans+=m;
			h=m-1;
		}
		for (int i=1;i<=h;i++) {
			ans+=i;
		}
		cout << ans << endl;
	}
	return 0;
}

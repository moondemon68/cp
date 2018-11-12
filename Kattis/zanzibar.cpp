#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int cur=1,ans=0;
		while (1>0) {
			int n;
			cin >> n;
			if (n==0) break;
			if (n>2*cur) {
				ans+=n-2*cur;
			}
			cur=n;
		}
		cout << ans << endl;
	}
	return 0;
}

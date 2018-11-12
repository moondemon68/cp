#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		int maxi=0,win=0,sum=0;
		bool y=0;
		for (int i=1;i<=n;i++) {
			int x;
			cin >> x;
			sum+=x;
			if (x>maxi) {
				win=i;
				maxi=x;
				y=0;
			} else if (x==maxi) {
				y=1;
			}
		}
		if (y) cout << "no winner" << endl;
		else if (!y&&maxi>sum/2) cout << "majority winner " << win << endl;
		else cout << "minority winner " << win << endl;
	}
	return 0;
}

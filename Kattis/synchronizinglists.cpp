#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	while (1>0) {
		cin >> n;
		if (n==0) return 0;
		pair<int,int> a[5005];
		int sorta[5005],b[5005];
		for (int i=1;i<=n;i++) cin >> a[i].first;
		for (int i=1;i<=n;i++) sorta[i]=a[i].first;
		sort (sorta+1,sorta+n+1);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (sorta[j]==a[i].first) {
					a[i].second=j;
					break;
				}
			}
		}
		for (int i=1;i<=n;i++) cin >> b[i];
		sort (b+1,b+n+1);
		for (int i=1;i<=n;i++) {
			cout << b[a[i].second] << endl;
		}
		cout << endl;
	}
	return 0;
}

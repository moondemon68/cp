#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		string a[105];
		for (int i=1;i<=n;i++) {
			cin >> a[i];
		}
		int ans=0;
		sort (a+1,a+n+1);
		a[n+1]="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		for (int i=1;i<=n;i++) {
			if (a[i]!=a[i+1]) ans++;
		}
		cout << ans << endl;
	}
}

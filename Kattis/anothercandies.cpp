#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		long long ans=0;
		for (int i=1;i<=n;i++) {
			long long x;
			cin >> x;
			ans+=x%n;
			ans%=n;
		}
		if (ans==0) cout << "YES"; else cout << "NO";
		cout << endl;
	}
	return 0;
}

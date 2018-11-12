#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int d,m;
		cin >> d >> m;
		int a[1005];
		vector<int> b;
		for (int i=1;i<=m;i++) cin >> a[i];
		for (int i=1;i<=m;i++) {
			for (int j=1;j<=a[i];j++) {
				b.push_back(j);
			}
		}
		int ans=0,day=6;
		for (int i=0;i<b.size();i++) {
			day++;
			if (day>7) day=1;
			if (b[i]==13&&day==5) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

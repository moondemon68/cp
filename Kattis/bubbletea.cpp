#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[1005];
	for (int i=1;i<=n;i++) cin >> a[i];
	
	int m;
	cin >> m;
	int b[1005];
	for (int i=1;i<=m;i++) cin >> b[i];
	
	int mini=INT_MAX;
	for (int i=1;i<=n;i++) {
		int x;
		cin  >> x;
		for (int j=1;j<=x;j++) {
			int y;
			cin >> y;
			mini=min(a[i]+b[y],mini);
		}
	}
	int p;
	cin >> p;
	cout << max(0,p/mini-1) << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,r;
	cin >> n >> r;
	bool a[105];
	memset (a,0,sizeof(a));
	for (int i=1;i<=r;i++) {
		int x;
		cin >> x;
		a[x]=1;
	}
	for (int i=1;i<=n;i++) {
		if (!a[i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "too late" << endl;
	return 0;
}

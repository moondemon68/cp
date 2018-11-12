#include <bits/stdc++.h>

using namespace std;

int main () {
	bool a[45];
	memset (a,0,sizeof(a));
	int ans=0;
	for (int i=1;i<=10;i++) {
		int x;
		cin >> x;
		a[x%42]=1;
	}
	for (int i=0;i<=41;i++) {
		if (a[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}

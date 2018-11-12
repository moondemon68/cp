#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a[105],b[10];
	memset (b,0,sizeof(b));
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		b[a[i]]++;
	}
	int ans=0;
	for (int i=1;i<=6;i++) {
		if (b[i]==1) ans=i;
	}
	if (ans==0) cout << "none" << endl;
	else {
		for (int i=1;i<=n;i++) {
			if (a[i]==ans) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}

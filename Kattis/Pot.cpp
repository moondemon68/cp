#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ans=0;
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		if (x%10==0) {
			ans++;
			continue;
		}
		int num=1;
		for (int j=1;j<=x%10;j++) {
			num*=x/10;
		}
		ans+=num;
	}
	cout << ans << endl;
	return 0;
}

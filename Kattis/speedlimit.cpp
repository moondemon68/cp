#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	while (1>0) {
		cin >> n;
		if (n==-1) return 0;
		int cur=0,ans=0;
		for (int i=1;i<=n;i++) {
			int a,b;
			cin >> a >> b;
			ans+=a*(b-cur);
			cur=b;
		}
		cout << ans << " miles" << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,t=0;
	while (cin >> n) {
		t++;
		int maxi=INT_MIN,mini=INT_MAX,x;
		for (int i=1;i<=n;i++) {
			cin >> x;
			maxi=max(maxi,x);
			mini=min(mini,x);
		}
		cout << "Case " << t <<": " << mini << ' ' << maxi << " " << maxi-mini << endl;
	}
	return 0;
}

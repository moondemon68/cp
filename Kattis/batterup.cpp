#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int cnt=0,sum=0;
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		if (x==-1) continue;
		cnt++;
		sum+=x;
	}
	cout << fixed << setprecision(7) << (double)sum/(double)cnt << endl;
	return 0;
}

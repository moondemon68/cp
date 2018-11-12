#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		double a[100005];
		double sum=0;
		for (int i=1;i<=n;i++) {
			cin >> a[i];
			sum+=a[i];
		}
		sum/=n;
		int p=0;
		for (int i=1;i<=n;i++) {
			if (a[i]>sum) p++;
		}
		cout << fixed << setprecision(3) << p*100/(double)n << "%" << endl;
	}
	return 0;
}

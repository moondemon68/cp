#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		vector<int> a;
		for (int i=1;i<=n;i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		sort (a.begin(),a.end());
		printf("Case #%d: ",t);
		for (int i=0;i<a.size();i++) {
			if (a[i]!=a[i+1]&&a[i]!=a[i-1]) {
				cout << a[i] << endl;
				break;
			}
		}
	}
}

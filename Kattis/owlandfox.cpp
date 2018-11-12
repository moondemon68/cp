#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		int div=0;
		while (n%10==0) {
			div++;
			n/=10;
		}
		n--;
		for (int i=0;i<div;i++) {
			n*=10;
		}
		cout << n << endl;
	}
	return 0;
}

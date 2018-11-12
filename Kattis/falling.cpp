#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		if (n%i==0) {
			int a=i,b=n/i;
			if ((a%2==0&&b%2==0)||(a%2==1&&b%2==1)) {
				cout << (b-a)/2 << " " << (b+a)/2 << endl;
				return 0;
			}
		}
	}
	cout << "impossible" << endl;
	return 0;
}

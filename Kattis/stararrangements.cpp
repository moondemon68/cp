#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	cout << n << ":" << endl;
	for (int i=2;i<=n/2+1;i++) {
		if ((n%(2*i-1)==0)||(n%(2*i-1)==i)) cout << i << ',' << i-1 << endl;
		if ((n%(2*i)==0)||(n%(2*i)==i)) cout << i << ',' << i << endl;
	}
	return 0;
}

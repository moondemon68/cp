#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		cout << x << " ";
		if (x%2==0) cout << "is even" << endl; else cout << "is odd" << endl;
	}
	return 0;
}

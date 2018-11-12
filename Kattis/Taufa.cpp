#include <bits/stdc++.h>

using namespace std;

int main () {
	int x;
	cin >> x;
	int n;
	cin >> n;
	int left=x;
	for (int i=1;i<=n;i++) {
		int p;
		cin >> p;
		left-=p;
		left+=x;
	}
	cout << left << endl;
	return 0;
}

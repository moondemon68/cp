#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b;
	cin >> a >> b;
	for (int i=-2000;i<=2000;i++) {
		if ((a+i)==2*b) {
			cout << i;
			break;
		}
	}
	return 0;
}

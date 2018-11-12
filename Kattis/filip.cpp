#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b;
	cin >> a >> b;
	int c=0,d=0;
	while (a>0) {
		c+=a%10;
		c*=10;
		a/=10;
	}
	while (b>0) {
		d+=b%10;
		d*=10;
		b/=10;
	}
	c/=10; d/=10;
	cout << max(c,d) << endl;
	return 0;
}

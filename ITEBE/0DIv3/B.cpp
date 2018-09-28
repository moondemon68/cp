#include <bits/stdc++.h>

using namespace std;
int main () {
	int a,b;
	cin >> b>>a;
	int p=pow(2,b);
	if (b>=30) {
		cout << a << endl;
	} else cout << a%p << endl;
	return 0;
}

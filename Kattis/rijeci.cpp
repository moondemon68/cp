#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int a=1,b=0;
	while (n--) {
		int newb=a+b,newa=b;
		a=newa;
		b=newb;
	}
	cout << a << " " << b << endl;
	return 0;
}

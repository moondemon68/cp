#include <bits/stdc++.h>

using namespace std;

int main () {
	double a,b,c;
	while (cin >> a >> b >> c) {
		if (a==0) return 0;
		cout << acos(-1)*a*a << " " << c/b*(2*a)*(2*a) << endl;
	} 
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int a,b;
	cin >> a >> b;
	int x=max(a,b);
	if (x==0) cout << "Not a moose" << endl;
	else if (a==b) cout << "Even " << x*2 << endl;
	else cout << "Odd " << x*2 << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		int x=b-c;
		if (a==x) cout << "does not matter" << endl;
		else if (a>x) cout << "do not advertise" << endl;
		else cout << "advertise" << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		cout <<fixed<<setprecision(0)<< pow(2,n)-1 << endl;
	}
	return 0;
}

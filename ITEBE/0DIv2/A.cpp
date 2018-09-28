#include <bits/stdc++.h>

using namespace std;

int main () {
	string a,b;
	cin >> a >> b;
	int x=0;
	for (int i=0;i<a.size();i++) {
		x+=a[i]-'0';
	}
	bool par=x%2;
	int y=0;
	for (int i=0;i<b.size();i++) {
		y+=b[i]-'0';
	}
	if ((par+x)<y) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}

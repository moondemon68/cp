#include <bits/stdc++.h>

using namespace std;

bool inc(string a,string b) {
	return a<b;
}

bool decr(string a,string b) {
	return a>b;
}

int main () {
	int n;
	cin >> n;
	string a[25],b[25],c[25];
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		b[i]=a[i];
		c[i]=a[i];
	}
	sort (b+1,b+n+1,inc);
	sort (c+1,c+n+1,decr);
	bool y=1;
	for (int i=1;i<=n;i++) {
		if (a[i]!=b[i]) y=0;
	}
	if (y) {
		cout << "INCREASING" << endl;
		return 0;
	}
	y=1;
	for (int i=1;i<=n;i++) {
		if (a[i]!=c[i]) y=0;
	}
	if (y) {
		cout << "DECREASING" << endl;
		return 0;
	}
	cout << "NEITHER" << endl;
	return 0;
}

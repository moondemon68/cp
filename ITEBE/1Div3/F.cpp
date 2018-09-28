#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,p,q;
	cin >> n>> p >> q;
	string s;
	cin >> s;
	for (int i=0;i<=100;i++) {
		for (int j=0;j<=100;j++) {
			if (i*p+j*q==n) {
				cout << i+j << endl;
				int a=0;
				for (int k=1;k<=i;k++) {
					for (int l=1;l<=p;l++) {
						cout << s[a];
						a++;
					}
					cout << endl;
				}
				for (int k=1;k<=j;k++) {
					for (int l=1;l<=q;l++) {
						cout << s[a];
						a++;
					}
					cout << endl;
				}
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}

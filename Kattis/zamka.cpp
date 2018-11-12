#include <bits/stdc++.h>

using namespace std;

int main () {
	int l,d,x;
	cin >> l >> d >> x;
	for (int i=l;i<=d;i++) {
		int t=i,s=0;
		while (t>0) {
			s+=t%10;
			t/=10;
		}
		if (s==x) {
			cout << i << endl;
			break;
		}
	}
	for (int i=d;i>=l;i--) {
		int t=i,s=0;
		while (t>0) {
			s+=t%10;
			t/=10;
		}
		if (s==x) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}

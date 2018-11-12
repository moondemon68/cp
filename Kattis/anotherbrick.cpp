#include <bits/stdc++.h>

using namespace std;

int main () {
	int h,w,n;
	cin >> h >> w >> n;
	int cw=0,ch=0;
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		cw+=x;
		if (cw>w) {
			cout << "NO" << endl;
			return 0;
		} else if (cw==w) {
			ch++;
			cw=0;
			if (ch==h) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
}

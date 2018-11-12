#include <bits/stdc++.h>

using namespace std;

int main () {
	int k;
	cin >> k;
	int n;
	cin >> n;
	int t=0;
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		t+=x;
		if (t>=210) {
			cout << k << endl;
			return 0;
		}
		char c;
		cin >> c;
		if (c=='T') {
			k++;
			if (k>8) k-=8;
		} 
	}
	return 0;
}

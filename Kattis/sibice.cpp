#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,w,h;
	cin >> n >> w >> h;
	int limit=sqrt(w*w+h*h);
	for (int i=1;i<=n;i++) {
		int x;
		cin >> x;
		if (x<=limit) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	for (int i=n+1;i<=9999;i++) {
		int x=i;
		set<int> p;
		while (x>0) {
			p.insert(x%10);
			x/=10;
		}
		if (p.size()==4) {
			cout << i << endl;
			return 0;
		}
	}
}

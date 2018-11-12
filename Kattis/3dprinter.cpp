#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ans=0;
	int printer=1;
	while (printer<n) {
		ans++;
		printer*=2;
	}
	cout << ans+1 << endl;
	return 0; 
}

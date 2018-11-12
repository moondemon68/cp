#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> bits;
	while (n>0) {
		bits.push_back(n%2);
		n/=2;
	}
	reverse(bits.begin(),bits.end());
	int ans=0,multiplier=1;
	for (int i=0;i<bits.size();i++) {
		ans+=multiplier*bits[i];
		multiplier*=2;
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	vector<int> a;
	int x;
	cin >> x;
	int y=x;
	while (x>0) {
		a.push_back(x%10);
		x/=10;
	}
	vector<int> ans;
	ans.push_back(y);
	sort (a.begin(),a.end());
	do {
		int p=0;
		for (int i=0;i<a.size();i++) {
			p+=a[i];
			p*=10;
		}
		p/=10;
		bool r=0;
		for (int i=0;i<ans.size();i++) {
			if (ans[i]==p) r=1;
		}
		if (!r) ans.push_back(p);
	} while (next_permutation(a.begin(),a.end()));
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++) {
		if (i==ans.size()-1) break;
		if (y==ans[i]) {
			cout << ans[i+1] << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}

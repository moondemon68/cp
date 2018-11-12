#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		string n,s,m;
		cin >> n >> s >> m;
		long long x=0;
		for (int i=0;i<n.size();i++) {
			for (int j=0;j<s.size();j++) {
				if (n[i]==s[j]) {
					x+=j;
					x*=s.size();
					break;
				}
			}
		}
		x/=s.size();
		vector<char> ans;
		while (x>0) {
			ans.push_back(m[x%m.size()]);
			x/=m.size();
		}
		cout << "Case #" << t << ": ";
		for (int i=ans.size()-1;i>=0;i--) cout << ans[i];
		cout << endl;
	}
	return 0;
}

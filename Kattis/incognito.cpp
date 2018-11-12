#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		map<string,int> a;
		vector<string> v;
		string r,s;
		for (int i=1;i<=n;i++) {
			cin >> r >> s;
			a[s]++;
			bool y=1;
			for (int j=0;j<v.size();j++) {
				if (v[j]==s) y=0;
			}
			if (y) v.push_back(s);
		}
		int ans=1;
		for (int i=0;i<v.size();i++) {
			ans*=a[v[i]]+1;
		}
		cout << ans-1 << endl;
	}
	return 0;
}

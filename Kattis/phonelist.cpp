#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
	//clock_t start = clock();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		set<string> p;
		vector<string> f;
		for (int i=1;i<=n;i++) {
			string s;
			cin >> s;
			f.pb(s);
			p.insert(s);
		}
		bool y=0;
		for (int i=0;i<f.size();i++) {
			while (!f[i].empty()) {
				f[i].erase(f[i].end()-1,f[i].end());
				//cout << f[i] << endl;
				auto it=p.find(f[i]);
				if (it!=p.end()) {
					y=1;
					break;
				}
			}
			if (y) break;
		}
		if (!y) cout << "YES"; else cout << "NO";
		cout << endl;
	}
	//cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
	return 0;
}
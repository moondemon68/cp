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
        string s;
        cin >> s;
        vector<string> ans;
        for (int i=0;i<s.size();i++) {
            if (s[i] != '0') {
                string p = "";
                p += s[i];
                for (int j=0;j<s.size()-i-1;j++) p += '0';
                ans.pb(p);
            }
        }
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
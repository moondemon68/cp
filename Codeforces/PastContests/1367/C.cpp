#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        vector<int> v;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '1') {
                v.pb(i);
            }
        }
        if (v.size() == 0) {
            cout << (n+k)/(k+1) << endl;
        } else if (v.size() == 1) {
            int x = v[0]-(k);
            int y = n - (v[0]+k+1);
            cout << max(0, (x+k)/(k+1)) + max(0, (y+k)/(k+1)) << endl;
        } else {
            int x = v[0]-(k);
            int y = n - (v[v.size()-1]+k+1);
            int ans = max(0, (x+k)/(k+1)) + max(0, (y+k)/(k+1));
            for (int i=0;i<v.size()-1;i++) {
                int p = v[i]+k+1;
                int q = v[i+1]-(k+1);
                int l = q-p+1;
                ans += max(0, (l+k)/(k+1));
            }
            cout << ans << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
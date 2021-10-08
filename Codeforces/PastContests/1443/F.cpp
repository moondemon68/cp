#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 998244353
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
        int a[n+5], loc[n+5];
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            loc[a[i]] = i;
        }
        int b[n+5];
        set<int> s;
        for (int i=1;i<=k;i++) {
            cin >> b[i];
            s.insert(b[i]);
        }
        s.insert(-99);
        a[0] = a[n+1] = -99;
        LL ans = 1;
        for (int i=1;i<=k;i++) {
            if (s.find(a[loc[b[i]]-1]) != s.end() && s.find(a[loc[b[i]]+1]) != s.end()) {
                ans = 0;
                break;
            } else if (s.find(a[loc[b[i]]-1]) != s.end() || s.find(a[loc[b[i]]+1]) != s.end()) {
                ans *= 1;
            } else {
                ans *= 2;
                ans %= MOD;
            }
            s.erase(s.find(b[i]));
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
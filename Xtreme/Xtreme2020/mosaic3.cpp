#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL ans = 0;
    string a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    map<string, LL> m;
    for (LL i=1;i<=n;i++) {
        m[a[i]]++;
    }
    string w = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        
    for (LL i=1;i<=n;i++) {
        for (LL k=0;k<14;k++) {
            if (a[i][k] == '-') continue;
            for (LL j=0;j<w.size();j++) {
                if (w[j] == a[i][k]) continue;
                char tmp = a[i][k];
                a[i][k] = w[j];
                ans += m[a[i]];
                a[i][k] = tmp;
            }
        }
    }
    cout << ans/2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
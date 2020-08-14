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
    LL n,mute,m;
    cin >> n >> mute >> m;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    vector<LL> small, big;
    for (LL i=1;i<=n;i++) {
        if (a[i] <= m) small.pb(a[i]);
        else big.pb(a[i]);
    }
    sort(small.begin(), small.end());
    reverse(small.begin(), small.end());
    sort(big.begin(), big.end());
    reverse(big.begin(), big.end());


    for (LL i=1;i<small.size();i++) {
        small[i] += small[i-1];
    }
    if (big.empty()) {
        cout << small.back() << endl;
        return 0;
    }

    for (LL i=1;i<big.size();i++) {
        big[i] += big[i-1];
    }

    LL ans = 0; // semua kecil
    for (LL i=(big.size() + mute)/(mute + 1)-1;i<big.size();i++) {
        LL rem = n - (i)*(mute+1) - 2;
        // cout << i << " " << rem << endl;
        if (rem >= 0 && rem < small.size()) {
            ans = max(ans, big[i] + small[rem]);
        } else if (rem >= 0) {
            LL tmp = 0;
            if (!small.empty()) tmp = small.back();
            ans = max(ans, big[i] + tmp);
        } else if (rem == -1) {
            ans = max(ans, big[i]);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
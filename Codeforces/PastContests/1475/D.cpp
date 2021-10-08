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

bool cmp(LL a, LL b) {
    return a > b;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,m;
        cin >> n >> m;
        pii a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i].fi;
        for (LL i=1;i<=n;i++) cin >> a[i].se;
        LL tot = 0;
        for (LL i=1;i<=n;i++) tot += a[i].fi;
        if (tot < m) {
            cout << -1 << endl;
            continue;
        }
        vector<LL> satu, dua;
        satu.pb(0);
        dua.pb(0);
        for (LL i=1;i<=n;i++) {
            if (a[i].se == 1) satu.pb(a[i].fi);
            else dua.pb(a[i].fi);
        }
        sort(satu.begin() + 1, satu.end(), cmp);
        sort(dua.begin() + 1, dua.end(), cmp);
        for (LL i=1;i<satu.size();i++) satu[i] += satu[i-1];
        for (LL i=1;i<dua.size();i++) dua[i] += dua[i-1];
        // cout << "satu: ";
        // for (LL i = 0; i < satu.size();i++) cout << satu[i] << " ";
        // cout << endl;
        // cout << "dua : ";
        // for (LL i = 0; i < dua.size();i++) cout << dua[i] << " ";
        // cout << endl;
        LL ans = INT_MAX;
        for (LL i=0;i<dua.size();i++) {    // ada ngambil dari dua kalo >= 0, -1 kalo ga ngambil
            LL x = i * 2, need = m - dua[i];
            if (need <= 0) {
                ans = min(ans, x);
                break;
            }
            if (need > satu[satu.size()-1]) {
                continue;
            }
            LL l = 0, h = satu.size()-1, y = -1;
            while (l <= h) {
                LL mid = (l + h) / 2;
                if (satu[mid] >= need) {
                    y = mid;
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // cout << x << " " << y << " " << need << endl;
            ans = min(ans, x + y);
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

LL inv[1000005];
LL cnt[1000005];

LL fpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res % MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=1000000;i++) {
        inv[i] = fpow(i, MOD-2);
        //cout << inv[i] << " ";
    }
    vector<int> a[n+5];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        for (int j=1;j<=x;j++) {
            int y;
            cin >> y;
            a[i].pb(y);
            cnt[y]++;
        }
    }
    LL ans=0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<a[i].size();j++) {
            ans += ((inv[n] * inv[a[i].size()]) % MOD)*((cnt[a[i][j]] * inv[n]) % MOD);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
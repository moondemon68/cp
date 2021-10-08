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

const LL MAXN = 3e5;

LL a[MAXN+5];

vector<LL> p;
bool prime[1000005];
void sieve(LL x) {
    memset (prime,1,sizeof(prime));
    prime[1] = 0;
    for (LL i=2;i*i<=x;i++) {
        if (!prime[i]) continue;
        for (LL j=i*i;j<=x;j+=i) {
            prime[j] = 0;
        }
    }
    for (LL i=2;i<=x;i++) {
        if (prime[i]) p.pb(i);
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(1000000);
    LL tc;
    cin >> tc;
    while (tc--) {
        map<LL,LL> hit;
        LL n;
        cin >> n;
        for (LL i=1;i<=n;i++) cin >> a[i];
        LL ans1 = 0;
        for (LL i=1;i<=n;i++) {
            LL cur = 1;
            LL po = 0;
            while (p[po] * p[po] <= a[i]) {
                LL cnt = 0;
                while (a[i] % p[po] == 0) {
                    cnt++;
                    a[i] /= p[po];
                }
                if (cnt % 2 == 1) cur *= p[po];
                po++;
            }
            cur *= a[i];
            hit[cur]++;
            ans1 = max(ans1, hit[cur]);
        }
        // for (LL i=1;i<=10;i++) cout << hit[i] << " ";
        // cout << endl;
        LL ans2 = 0;
        for (auto x : hit) {
            if (x.se % 2 == 0 || x.fi == 1) ans2 += x.se;
        }
        LL q;
        cin >> q;
        while (q--) {
            LL x;
            cin >> x;
            if (x == 0) cout << ans1 << endl;
            else cout << max(ans1, ans2) << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
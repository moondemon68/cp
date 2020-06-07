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

vector<LL> p;
bool prime[200005];
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
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    sieve(200000);
    map<LL,vector<LL>> m;
    for (LL i=1;i<=n;i++) {
        LL k = 0;
        while (a[i] > 1) {
            if (prime[a[i]]) {
                m[a[i]].pb(1);
                break;
            }
            LL cnt = 0;
            while (a[i] % p[k] == 0) {
                cnt++;
                a[i] /= p[k];
            }
            if (cnt > 0) m[p[k]].pb(cnt);
            k++;
        }
    }
    LL ans = 1;
    for (LL i=1;i<=200000;i++) {
        if (m[i].size() == n) {
            sort (m[i].begin(), m[i].end());
            ans *= pow(i, m[i][1]);
        } else if (m[i].size() == n-1) {
            m[i].pb(0);
            sort (m[i].begin(), m[i].end());
            ans *= pow(i, m[i][1]);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    // trivial: untuk tiap prime, ask B, ask A lagi. kalo sisa 1 A nya berarti angkanya punya faktor prima itu.
    int n;
    cin >> n;
    sieve(n);
    int cnt = 0;
    int ans = 1;
    for (LL x : p) {
        LL cur = x;
        LL cand = 1;
        while (cur <= n) {
            cnt++;
            cout << "B " << cur << endl;
            int rep;
            cin >> rep;
            if ((rep >= 2 && cur == x) || (rep >= 1 && cur != x)) {
                cand = cur;
            } else break;
            cur *= x;
        }
        ans *= cand;
    }
    cout << "C " << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
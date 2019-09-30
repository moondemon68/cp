#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL poww(LL a, LL x) {
    LL ret = 1;
    while (x > 0) {
        if (x % 2 == 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        x /= 2;
    }
    return ret % MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL x,n;
    cin >> x >> n;
    vector<LL> p;
    set<LL> s;
    while (x % 2 == 0) {
        if (p.size()==0) p.pb(2);
        x/=2;
    }
    for (LL i=3;i*i<=x;i+=2) {
        while (x%i==0) {
            if (s.find(i) == s.end()) {
                s.insert(i);
                p.pb(i);
            }
            x/=i;
        }
    }
    if (x > 2) p.pb(x);
    LL ans=1, g = 0;

    for (LL i=0;i<p.size();i++) {
        g = 0;
        x = 1;
        while (x <= n) {
            LL tmp = x * p[i];
            if (x != 0 && tmp / x != p[i]) {
                // overflow handling
                break;
            }
            if (tmp > n) break;
            g += n/tmp;
            x = tmp;
        }
        //cout << p[i] << " " << g << endl;
        ans *= poww(p[i], g);
        ans %= MOD;
    }
    
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
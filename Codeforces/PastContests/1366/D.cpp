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

int spf[10000005];
void sieve(LL x) {
    for (int i=1;i<=x;i++) spf[i] = 1;
    for (int i=1;i<=x;i++) {
        if (spf[i] == 1) {
            for (LL j=i;j<=x;j+=i) {
                spf[j] = i;
            }
        }
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(10000000);
    vector<int> ansa,ansb;
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        int tx = x;
        set<int> s;
        while (x > 1) {
            s.insert(spf[x]);
            x /= spf[x];
        }
        vector<int> a;
        for (auto p : s) a.pb(p);
        int sz = a.size();
        bool y = 0;
        for (int j=0;j<sz;j++) {
            int kk = 1;
            for (int k=j+1;k<sz;k++) {
                kk *= a[k];
            }
            if (__gcd(a[j]+kk, tx) == 1 && kk > 1) {
                ansa.pb(a[j]);
                ansb.pb(kk);
                y = 1;
                break;
            }
            if (y) break;
        }
        if (!y) {
            ansa.pb(-1);
            ansb.pb(-1);
        }
    }

    for (auto x : ansa) cout << x << " ";
    cout << endl;
    for (auto x : ansb) cout << x << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
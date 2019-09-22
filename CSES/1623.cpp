#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL g=0;
    for (int i=1;i<=n;i++) g+=a[i];
    LL ans=12345678987654321;
    for (LL i=0;i<(1<<n);i++) {
        LL x=i;
        vector<LL> p;
        while (p.size()<n) {
            p.pb(x%2);
            x/=2;
        }
        LL k=0;
        for (LL j=0;j<p.size();j++) if (p[j]) k+=a[j];
        ans=min(ans,abs((g-k)-k));
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
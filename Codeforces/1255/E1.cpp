#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    vector<LL> p;
    for (LL i=1;i<=n;i++) {
        if (a[i] == 1) p.pb(i);
    }
    if (p.size() == 1) cout << -1 << endl;
    else {
        LL ans=0;
        for (LL i=0;i<p.size()-1;i+=2) {
            ans+=p[i+1]-p[i];
        }
        if (p.size()%2 == 1) {
            ans+=p[p.size()-1]-p[p.size()-2];
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    sort (a+1,a+n+1);
    reverse(a+1,a+n+1);
    vector<LL> p;
    for (LL i=1;i<=n;i++) {
        if (a[i]==a[i+1]||a[i]==a[i+1]+1) {
            p.pb(a[i+1]);
            i++;
        }
    }
    LL ans=0;
    if (p.size()%2==0) {
        for (LL i=0;i<p.size();i+=2) ans+=p[i]*p[i+1];
    } else {
        for (LL i=0;i<p.size()-1;i+=2) ans+=p[i]*p[i+1];
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
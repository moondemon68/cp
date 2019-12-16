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
    LL n,m;
    cin >>n >> m;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    LL p[m+5],q[m+5];
    memset (p,0,sizeof(p));
    memset (q,0,sizeof(q));
    LL cur=0;
    for (LL i=1;i<=n;i++) {
        p[i%m] += a[i];
        cur += p[i%m];
        cout << cur << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
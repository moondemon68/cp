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
    LL n,p,q;
    cin >> n >> p >> q;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    bool u[n+5],v[n+5];
    memset (u,0,sizeof(u));
    memset (v,0,sizeof(v));
    for (LL i=1;i<=p;i++) {
        LL x;
        cin >> x;
        u[x]=1;
    }
    for (LL i=1;i<=q;i++) {
        LL x;
        cin >> x;
        v[x]=1;
    }
    priority_queue<LL> pq;
    for (LL i=1;i<=n;i++) {
        if (u[i]&&v[i]) pq.push(a[i]);
    }
    LL ans=0;
    bool y=1;
    while (!pq.empty()) {
        if (y) ans+=pq.top();
        pq.pop();
        y=!y;
    }
    for (LL i=1;i<=n;i++) {
        if (u[i]&&!v[i]) ans+=a[i];
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
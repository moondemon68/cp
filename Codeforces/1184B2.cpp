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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    LL d[n+5][n+5];
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=n;j++) {
            d[i][j]=123456780;
        }
    }
    for (LL i=1;i<=m;i++) {
        LL x,y;
        cin >> x >> y;
        d[x][y]=1;
        d[y][x]=1;
    }
    for (LL i=1;i<=n;i++) d[i][i]=0;
    for (LL k=1;k<=n;k++) {
        for (LL i=1;i<=n;i++) {
            for (LL j=1;j<=n;j++) {
                if (d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    LL s,b,k,h;
    cin >> s >> b >> k >> h;
    if (h<=k) {
        cout << h*s << endl;
        return 0;
    } 
    vector<pair<pii,LL>> sp; //location,attack,fuel
    vector<pii> ba; //location,def
    for (LL i=1;i<=s;i++) {
        LL p,q,r;
        cin >> p >> q >> r;
        sp.pb(mp(mp(p,q),r));
    }
    for (LL i=1;i<=b;i++) {
        LL p,q;
        cin >> p >> q;
        ba.pb(mp(p,q));
    }
    vector<LL> a;
    for (LL i=1;i<=s;i++) {
        LL cnt=0;
        for (LL j=1;j<=b;j++) {
            if (sp[i].se<=d[sp[i].fi.fi][ba[j].fi]&&sp[i].fi.se>=ba[j].se) cnt++;
        }
        a.pb(cnt);
    }
    sort (a.begin(),a.end());
    LL ans=0,l=0,h=1234567890987654321;
    for (LL i=0;i<a.size();i++) {
        ans=min(ans,a[i]*k+(b-a[i])*h);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n,m;
    cin >> n >> m;
    int a[n+5],b[n+5],sum=0,sumb=0;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n;i++) {
        cin >> b[i];
        sumb+=b[i];
    }
    if (sum!=sumb) {
        cout << "NO" << endl;
        return 0;
    }
    Dinic d(n*2+2,0,n*2+1);
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        d.add_edge(x,y+n,1e9);
        d.add_edge(y,x+n,1e9);
    }
    for (int i=1;i<=n;i++) d.add_edge(0,i,a[i]);
    for (int i=1;i<=n;i++) d.add_edge(i+n,n*2+1,b[i]);
    for (int i=1;i<=n;i++) d.add_edge(i,i+n,1e9);
    if (d.flow() == sum) {
        cout << "YES" << endl;
        LL ans[n+5][n+5];
        memset (ans,0,sizeof(ans));
        for (int i=0;i<d.edges.size();i++) {
            //cout << d.edges[i].u << " " << d.edges[i].v << " " << d.edges[i].flow << " " << d.edges[i].cap <<  endl;
            if (d.edges[i].cap>0) ans[d.edges[i].v][d.edges[i].u-n]+=d.edges[i].flow;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    vector<pii> v;
    int x = (1<<m)-1;
    for (int i=1;i<=x;i++) {
        for (int j=1;j<=x;j++) {
            if ((i|j) == x) {
                v.pb(mp(i,j));
            }
        }
    }
    // cout << v.size() << endl;
    int l=0,h=1e9,ans=0, a1=0,a2=0;
    while (l <= h) {
        int mid = (l+h)/2;
        bool y = 0;
        int b[n+5];
        vector<int> k[x+5];
        for (int i=1;i<=n;i++) {
            int p = 0;
            for (int j=1;j<=m;j++) {
                if (a[i][j]>=mid) p++;
                p*=2;
            }
            p/=2;
            b[i] = p;
            k[p].pb(i);
        }
        for (int i=0;i<v.size();i++) {
            if (k[v[i].fi].size() >= 1 && k[v[i].se].size() >= 1) {
                y = 1;
                a1 = k[v[i].fi][0];
                a2 = k[v[i].se][0];
                break;
            }
        }
        if (k[x].size() >= 2) {
            y = 1;
            a1 = k[x][0];
            a2 = k[x][1];
        }
        if (y) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    // cout << ans << endl;
    cout << a1 << " " << a2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5][n+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int,pii>> v;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            v.pb({a[i][j], {i,j}});
        }
    }
    sort (v.begin(), v.end());
    int p[n+5];
    memset (p,0,sizeof(p));
    int ans = 0;
    for (int i=0;i<v.size();i++) {
        if (p[v[i].se.fi] == 0) {
            p[v[i].se.fi] = 1;
            int x = INT_MAX;
            for (int j=1;j<=n;j++) {
                for (int k=j+1;k<=n;k++) {
                    if (p[j] == p[k]) x = min(x, a[j][k]);
                }
            }
            ans = max(ans, x);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
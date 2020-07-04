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

vector<int> v[200005];
vector<int> v2[200005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pii a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    for (int i=1;i<=n;i++) {
        v[a[i].se].pb(a[i].fi);
    }
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++) {
        v2[a[i].se].pb(a[i].fi);
    }
    bool y = 1;
    for (int i=1;i<=200000;i++) {
        for (int j=0;j<v[i].size();j++) {
            if (v[i][j] != v2[i][j]) {
                y = 0;
            }
        }
    }
    if (y) cout << "YES" << endl;
    else cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
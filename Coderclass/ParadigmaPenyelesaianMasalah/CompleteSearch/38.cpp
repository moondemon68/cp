//Prototipe Robot Pempek
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
    int n,m,k,q;
    cin >> n >> m >> k >> q;
    string a[n+5];
    for (int i=0;i<n;i++) cin >> a[i];
    vector<pii> p;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (a[i][j]=='X') p.pb(mp(i+1,j+1));
        }
    }
    while (q--) {
        int x,y;
        cin >> x >> y;
        int ans=1234567890;
        for (int i=0;i<p.size();i++) {
            ans=min(ans,abs(p[i].fi-x)+abs(p[i].se-y));
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
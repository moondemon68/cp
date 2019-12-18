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
    int n,m,q;
    cin >> n >> m >> q;
    string s,t;
    cin >> s >> t;
    int ans[n+5];
    memset (ans,0,sizeof(ans));
    for (int i=1;i<=n;i++) {
        int ps=i-1,pt=0;
        while (ps<n&&pt<m) {
            if (s[ps]==t[pt]&&pt==m-1) {
                ans[i]++;
                ps++;
                pt++;
            } else if (s[ps]==t[pt]) {
                ps++;
                pt++;
            } else {
                ps++;
                break;
                pt=0;
            }
        }
    }
    for (int i=2;i<=n;i++) ans[i]+=ans[i-1];
    while (q--) {
        int x,y;
        cin >> x >> y;
        if (y-x+1<m) cout << 0; else cout << ans[y-m+1]-ans[x-1];
        cout << endl;
    }
    //for (int i=1;i<=n;i++) cout << ans[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
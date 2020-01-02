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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m,q;
        cin >> m >> n >> q;
        bool b[n+5];
        memset (b,1,sizeof(b));
        for (int i=1;i<=m;i++) {
            int x,y;
            cin >> x >> y;
            for (int j=x;j<=y;j++) {
                b[j]=0;
            }
        }
        int ans[n+5];
        memset(ans,-1,sizeof(ans));
        int p=1;
        for (int i=n;i>=1;i--) {
            //cout << i << endl;
            int cnt=0;
            if (b[i]) {
                if (ans[1] == -1) ans[1] = i;
                for (int j=i;j>=1;j--) {
                    if (!b[j]) break;
                    cnt++;
                }
                for (int j=p+1;j<=cnt;j++) {
                    ans[j] = i;
                }
                i -= cnt;
                p = max(p, cnt);
            }
        }
        // for (int i=1;i<=n;i++) cout << ans[i] << " ";
        // cout << endl;
        for (int i=1;i<=q;i++) {
            int x;
            cin >> x;
            if (ans[x] == -1) cout << "-1 -1" << "\n";
            else cout << ans[x]-x+1 << " " << ans[x] << "\n";
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
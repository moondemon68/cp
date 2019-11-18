#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int a[200005], n;
pii p[200005];



int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        memset (a,0,sizeof(a));
        cin >> n;
        int maxmonster = 0;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            maxmonster = max(maxmonster, a[i]);
        }
        int m;
        cin >> m;
        int maxplayer = 0;
        for (int i=1;i<=m;i++) {
            cin >> p[i].fi >> p[i].se;
            maxplayer = max(maxplayer, p[i].fi);
        }
        if (maxplayer<maxmonster) {
            cout << -1 << endl;
            continue;
        }
        int k=1;
        int maxp[200005];
        memset (maxp,0,sizeof(maxp));
        for (int i=1;i<=m;i++) {
            maxp[p[i].se] = max(maxp[p[i].se], p[i].fi);
        }
        for (int i=n-1;i>=1;i--) maxp[i] = max(maxp[i], maxp[i+1]);
        // for (int i=1;i<=n;i++) {
        //     cout << maxp[i] << " ";
        // }
        // cout << endl;
        
        int ans=0;
        for (int i=1;i<=n;i++) {
            int cnt=0;
            int x=0;
            while (cnt+i<=n) {
                int j=i+cnt;
                x=max(x, a[j]);
                if (maxp[cnt+1] >= x) cnt++;
                else break;
            }
            cnt--;
            i+=cnt;
            ans++;
            //cout << x << cnt << endl;
        }
        cout << ans << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
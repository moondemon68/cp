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
        int n;
        cin >> n;
        int ans[n+5];
        memset (ans,0,sizeof(ans));
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        bool done[n+5];
        memset (done, 0, sizeof(done));
        ans[1]=a[1];
        done[a[1]]=1;
        for (int i=2;i<=n;i++) {
            if (a[i]==a[i-1]) continue;
            else {
                ans[i]=a[i];
                done[a[i]] = 1;
            }
        }
        int x = 1;
        for (int i=1;i<=n;i++) {
            if (ans[i] == 0) {
                while (done[x]) {
                    x++;
                }
                ans[i]=x;
                done[x]=1;
                x++;
            }
        }
        bool y=1;
        int maxi = 1;
        int pre[n+5];
        memset (pre,0,sizeof(pre));
        for (int i=1;i<=n;i++) {
            pre[i] = max(pre[i-1], ans[i]);
        }
        for (int i=1;i<=n;i++) {
            if (pre[i] != a[i]) y=0;
        }
        if (y) {
            for (int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,m;
        cin >> n >> m;
        LL a[n+5], b[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        for (LL i=1;i<=m;i++) cin >> b[i];
        LL ans=0;
        stack<LL> s;
        for (LL i=n;i>=1;i--) s.push(a[i]);
        LL cur=0;
        bool done[n+5];
        memset (done,0,sizeof(done));
        for (LL i=1;i<=m;i++) {
            LL cnt=0;
            if (done[b[i]]) {
                cur--;
                ans++;
                // cout << "PAKE" << endl;
                continue;
            }
            while (!s.empty() && s.top() != b[i]) {
                cnt++;
                done[s.top()] = 1;
                s.pop();
            }
            // cout << cnt << " " << cur << endl;
            s.pop();
            ans+=2*(cnt+cur)+1;
            cur+=cnt;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
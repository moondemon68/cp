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
        LL n,k;
        cin >> n >> k;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        LL w[k+5];
        for (LL i=1;i<=k;i++) cin >> w[i];
        sort (a+1,a+n+1);
        reverse(a+1,a+n+1);
        sort (w+1,w+k+1);
        LL ans = 0;
        for (LL i=1;i<=k;i++) {
            ans += a[i];
            if (w[i] == 1) ans += a[i];
        }
        // cout << ans << endl;
        priority_queue<LL, vector<LL>, greater<LL>> p;
        for (LL i=k+1;i<=n;i++) {
            p.push(a[i]);
        }
        reverse(w+1,w+k+1);
        for (LL i=1;i<=k;i++) {
            if (w[i] > 1) {
                // cout << p.top() << " ";
                ans += p.top();
                for (LL j=2;j<=w[i];j++) {
                    p.pop();
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
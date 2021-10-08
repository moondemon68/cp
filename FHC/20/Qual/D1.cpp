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

LL a[1000005];
LL dp[1000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("running_on_fumes_chapter_1_input.txt");
    ofstream cout("running_on_fumes_chapter_1_output.txt");
    LL tc;
    cin >> tc;
    for (LL t=1;t<=tc;t++) {
        LL n, m;
        cin >> n >> m;
        for (LL i=1;i<=n;i++) cin >> a[i];
        memset (dp,0,sizeof(dp));
        priority_queue<pii, vector<pii>, greater<pii>> p;
        for (LL i=2;i<=m+1;i++) {
            if (a[i] > 0) p.push({a[i], i});
        }
        for (LL i=m+2;i<=n;i++) {
            dp[i] = 123456789876543210;
            // for (LL j=i-m;j<i;j++) {
            //     if (j >= 1 && a[j] > 0) dp[i] = min(dp[i], dp[j] + a[j]);
            // }
            while (!p.empty()) {
                pii top = p.top();
                if (top.se < i-m) {
                    p.pop();
                    continue;
                }
                dp[i] = top.fi;
                if (a[i] > 0) p.push({dp[i] + a[i], i});
                break;
            }
            // cout << dp[i] << " ";
        }
        cout << "Case #" << t << ": ";
        if (dp[n] == 123456789876543210) cout << -1 << endl; else cout << dp[n] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
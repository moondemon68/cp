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
    LL n;
    cin >> n;
    LL p[n+5], a[n+5];
    for (LL i=1;i<=n;i++) cin >> p[i];
    for (LL i=1;i<=n;i++) cin >> a[i];
    bool vis[n+5];
    memset(vis,0,sizeof(vis));
    LL ans = 0;
    for (LL i=1;i<=n;i++) {
        if (vis[i]) continue;
        stack<LL> s;
        s.push(i);
        vis[i] = 1;
        queue<LL> q;
        LL mini = INT_MAX;
        while (!s.empty()) {
            LL cur = s.top();
            s.pop();
            q.push(cur);
            LL next = a[cur];
            if (vis[next]) {
                while (!q.empty() && q.front() != next) {
                    q.pop();
                }
                while (!q.empty()) {
                    // cout << q.front() << " ";
                    mini = min(mini, p[q.front()]);
                    q.pop();
                }
                // cout << endl;
                break;
            } else {
                vis[next] = 1;
                s.push(next);
            }
        }
        if (mini != INT_MAX) ans += mini;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
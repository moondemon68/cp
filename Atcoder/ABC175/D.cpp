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
    LL n, k;
    cin >> n >> k;
    LL p[n+5];
    for (LL i=1;i<=n;i++) cin >> p[i];
    LL c[n+5];
    for (LL i=1;i<=n;i++) cin >> c[i];

    bool vis[n+5];
    memset (vis,0,sizeof(vis));

    LL ans = INT_MIN;
    for (LL i=1;i<=n;i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        stack<LL> s;
        s.push(i);
        vector<LL> v;
        v.pb(c[i]);
        while (!s.empty()) {
            LL cur = s.top();
            s.pop();
            LL next = p[cur];
            if (!vis[next]) {
                s.push(next);
                vis[next] = 1;
                v.pb(c[next]);
            }
        }
        LL sum = 0;
        for (auto x : v) {
            sum += x;
        }
        vector<LL> w;
        for (auto x : v) {
            w.pb(x);
        }
        for (auto x : v) {
            w.pb(x);
        }

        // for (auto x : v) {
        //     cout << x << " ";
        // }
        // cout << sum;
        // cout << endl;

        LL limit = 0;
        if (k >= v.size()) limit = v.size();
        else limit = k;

        LL sesuatu = INT_MIN;
        for (LL j=1;j<w.size();j++) w[j] += w[j-1];
        for (LL j=0;j<w.size();j++) {
            for (LL l=j;l<min(j+limit, (LL)w.size());l++) {
                if (j > 0) sesuatu = max(sesuatu, w[l]-w[j-1]);
                else sesuatu = max(sesuatu, w[l]);
            }
        }

        LL sesuatu2 = INT_MIN;
        for (LL j=0;j<w.size();j++) {
            for (LL l=j;l<min(j+(k%(LL)v.size()), (LL)w.size());l++) {
                if (j > 0) sesuatu2 = max(sesuatu2, w[l]-w[j-1]);
                else sesuatu2 = max(sesuatu2, w[l]);
            }
        }

        if (sum >= 0) { // positive cycle
            ans = max(ans, k/(LL)v.size() * sum + sesuatu2);
            ans = max(ans, (k/(LL)v.size()-1) * sum + sesuatu);
        } else {
            ans = max(ans, sesuatu);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
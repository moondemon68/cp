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
    pii a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi;
    for (LL i=1;i<=n;i++) cin >> a[i].se;
    sort (a+1,a+n+1);

    set<int> s;
    priority_queue<LL> p;
    map<LL, vector<LL>> m;
    for (LL i=1;i<=n;i++) {
        s.insert(a[i].fi);
        m[a[i].fi].pb(a[i].se);
    }

    LL ans = 0, cur = 0, minx = a[1].fi, i = 1;
    for (auto ai : s) {
        if (m[ai].size() > 1 || !p.empty()) {
            for (auto x : m[ai]) {
                cur += x;
                p.push(x);
            }
            cur -= p.top();
            p.pop();
            minx = ai;
            while (!p.empty()) {
                ans += cur;
                minx++;
                if (!m[minx].empty()) break;
                cur -= p.top();
                p.pop();
            }
        }
    }
    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
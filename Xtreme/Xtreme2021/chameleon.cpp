#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

const LL INF = 1e18;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n, m, k;
        cin >> n >> m >> k;
        vector<pair<LL, pair<LL, char>>> adj[n+5];
        for (LL i=1;i<=m;i++) {
            LL u, v, w;
            char c;
            cin >> u >> v >> w >> c;
            adj[u].pb({v, {w, c}});
            adj[v].pb({u, {w, c}});
        }
        LL l = 1, h = 1e9, ans = 0;
        while (l <= h) {
            LL mid = (l+h) / 2;
            vector<LL> d((n + 2) * 5, INF);
            priority_queue<pair<pii, char>, vector<pair<pii, char>>, greater<pair<pii, char>>> pq;
            d[5] = 0;
            pq.push({{0, 1}, 'a'});
            while (!pq.empty()) {
                auto it = pq.top();
                LL v = it.fi.se;
                pq.pop();
                if (d[v*5+(it.se-'a')] != it.fi.fi) continue;
                for (auto next : adj[v]) {
                    LL dist = next.se.fi;
                    if (next.se.se != it.se) {
                        dist += mid;
                    }
                    if (d[v*5+(it.se-'a')] + dist < d[next.fi*5 + (next.se.se-'a')]) {
                        d[next.fi*5 + (next.se.se-'a')] = d[v*5+(it.se-'a')] + dist;
                        pq.push({{d[next.fi*5 + (next.se.se-'a')], next.fi}, next.se.se});
                    }
                }
            }
            if (min({d[n*5], d[n*5+1], d[n*5+2], d[n*5+3], d[n*5+4]}) <= k) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        if (ans == 0) {
            cout << "impossible" << endl;
        } else if (ans == 1e9) {
            cout << "relaxing" << endl;
        } else {
            cout << ans << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
5 6 60
1 2 20 b
1 3 40 b
2 3 10 a
2 4 10 a
5 4 10 a
5 3 20 a
*/
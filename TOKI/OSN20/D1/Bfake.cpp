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
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL q;
    cin >> q;
    LL ask[q+5];
    for (LL i=1;i<=q;i++) cin >> ask[i];
    
    vector<pair<pii, LL>> v;

    // TLE 50
    // LL start = 1;
    // while (start <= n) {
    //     if (a[start] == 0) {
    //         start++;
    //         continue;
    //     }
    //     LL mini = INT_MAX;
    //     LL p = start;
    //     while (p <= n) {
    //         if (a[p] == 0) {
    //             p--;
    //             break;
    //         }
    //         mini = min(mini, a[p]);
    //         p++;
    //     }
    //     if (p > n) p = n;
    //     for (LL i=start;i<=p;i++) {
    //         a[i] -= mini;
    //     }
    //     v.pb({{start, p}, mini});
    // }

    // Subtask 6
    // LL start = 1;
    // LL curmin = 0;
    // while (start <= n) {
    //     if (a[start] - curmin == 0) {
    //         start++;
    //         continue;
    //     }
    //     LL mini = a[start] - curmin;
    //     LL p = n;
    //     v.pb({{start, p}, mini});
    //     curmin += mini;
    //     start++;
    // }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    a[n+1] = 0;
    LL last = 1;
    for (int i=1;i<=n+1;i++) {
        if (a[i] == 0 && last <= i-1) {
            pq.push({last, i-1});
        }
        if (a[i] == 0) last = i+1;
    }

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        // cout << cur.fi << " " << cur.se << endl;
        LL mini = INT_MAX;
        for (int i=cur.fi;i<=cur.se;i++) {
            mini = min(mini, a[i]);
        }
        for (int i=cur.fi;i<=cur.se;i++) {
            a[i] -= mini;
        }
        v.pb({{cur.fi, cur.se}, mini});
        last = cur.fi;
        for (int i=cur.fi;i<=cur.se+1;i++) {
            if (a[i] == 0 && last <= i-1) {
                pq.push({last, i-1});
            }
            if (a[i] == 0) last = i+1;
        }
    }

    // LL last = 1;
    // for (int i=1;i<=n;i++) {
    //     if (b[i].fi == 0) {
    //         LL start = last, fin = b[i].se-1;

    //     }
    // }

    // LL start = 1;
    // while (start <= n) {
    //     if (a[start] == 0) {
    //         start++;
    //         continue;
    //     }
    //     LL mini = INT_MAX;
    //     LL p = start;
    //     while (p <= n) {
    //         if (a[p] == 0) {
    //             p--;
    //             break;
    //         }
    //         mini = min(mini, a[p]);
    //         p++;
    //     }
    //     if (p > n) p = n;
    //     for (LL i=start;i<=p;i++) {
    //         a[i] -= mini;
    //     }
    //     v.pb({{start, p}, mini});
    // }

    // RTE 29
    // vector<LL> ans;
    // for (LL i=0;i<v.size();i++) {
    //     for (LL j=1;j<=v[i].se;j++) {
    //         for (LL k=v[i].fi.fi;k<=v[i].fi.se;k++) {
    //             ans.pb(k);
    //         }
    //     }
    // }
    // for (LL i=1;i<=q;i++) cout << ans[ask[i]-1] << endl;


    vector<LL> p;
    LL cur = 0;
    p.pb(cur);
    for (LL i=0;i<v.size();i++) {
        cur += (v[i].fi.se - v[i].fi.fi + 1) * v[i].se;
        p.pb(cur);
    }

    // DEBUG
    for (LL i=0;i<v.size();i++) {
        cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se << endl;
    }

    for (LL i=1;i<=q;i++) {
        LL x = ask[i];
        LL l = 0, r = v.size()-1, found = -1;
        while (l <= r) {
            LL m = (l + r) / 2;
            if (x > p[m]) {
                found = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        LL pos = x - p[found];
        // cout << found << " " << pos << endl;
        pos--;
        pos %= (v[found].fi.se - v[found].fi.fi + 1);
        cout << v[found].fi.fi + pos << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
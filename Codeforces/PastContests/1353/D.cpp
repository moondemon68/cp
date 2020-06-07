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

struct cmp {
    bool operator()(const pii& a, const pii& b) {
        if (a.se == b.se) return a.fi > b.fi;
        else return a.se < b.se;
    }
};

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
        priority_queue<pii, vector<pii>, cmp> p;
        int a[n+5];
        int cnt = 1;
        p.push({1,n});
        while (!p.empty()) {
            pii cur = p.top();
            // cout << cur.fi << " " << cur.se << endl;
            p.pop();
            if (cur.se == 1) {
                a[cur.fi] = cnt;
            } else if (cur.se == 2) {
                a[cur.fi] = cnt;
                p.push({cur.fi+1, 1});
            } else if (cur.se % 2 == 1) {
                a[cur.fi+cur.se/2] = cnt;
                p.push({cur.fi, cur.se/2});
                p.push({cur.fi+cur.se/2 + 1, cur.se/2});
            } else {
                a[cur.fi+cur.se/2 - 1] = cnt;
                p.push({cur.fi, cur.se/2 - 1});
                p.push({cur.fi+cur.se/2, cur.se/2});
            }
            cnt++;
        }
        for (int i=1;i<=n;i++) cout << a[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    double eps = 1e-10;
    stack<pair<double, int>> s;
    s.push({a[1], 1});
    for (int i=2;i<=n;i++) {
        double x = a[i];
        int cnt = 1;
        while (!s.empty() && s.top().fi + eps > x) {
            x = 1.0 * (s.top().fi * s.top().se + x * cnt) / (cnt + s.top().se);
            cnt += s.top().se;
            s.pop();
        }
        s.push({x, cnt});
    }

    vector<pair<double, int>> ans;
    while (!s.empty()) {
        ans.pb(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << fixed << setprecision(9);
    for (auto x : ans) {
        for (int i=0;i<x.se;i++) {
            cout << x.fi << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
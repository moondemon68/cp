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
    ifstream cin("5.txt");
    ofstream cout("5out.txt");
    int tc;
    cin >> tc;
    while (tc--) {
        int m,k,n;
        cin >> m >> k >> n;
        double a[m+5], b[k+5];
        for (int i=1;i<=m;i++) cin >> a[i];
        for (int i=1;i<=k;i++) cin >> b[i];
        vector<pair<double, pii>> v;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                if ((a[i] + b[j]) > 0) v.pb({a[i] + b[j], {i, j}});
            }
        }
        sort(v.begin(), v.end());
        while (n--) {
            pii ans = {-1, -1};
            double mini = 1e9;
            double x;
            cin >> x;
            // for (int i = 0; i < v.size(); i++) {
            //     if (abs(x - v[i].first) < mini) {
            //         mini = abs(x - v[i].first);
            //         ans = v[i].second;
            //     }
            // }
            if (x <= v[0].fi) {
                ans = v[0].se;
            } else if (x >= v[v.size() - 1].fi) {
                ans = v[v.size() - 1].se;
            } else {
                int l = 0, r = v.size() - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (x == v[mid].fi) {
                        ans = v[mid].se;
                        break;
                    } else if (x < v[mid].fi) {
                        if (mid > 0 && x > v[mid - 1].fi) {
                            if (abs(x - v[mid].fi) < abs(x - v[mid - 1].fi)) {
                                ans = v[mid].se;
                            } else {
                                ans = v[mid - 1].se;
                            }
                            break;
                        } else {
                            r = mid - 1;
                        }
                    } else {
                        if (mid < v.size() - 1 && x < v[mid + 1].fi) {
                            if (abs(x - v[mid].fi) < abs(x - v[mid + 1].fi)) {
                                ans = v[mid].se;
                            } else {
                                ans = v[mid + 1].se;
                            }
                            break;
                        } else {
                            l = mid + 1;
                        }
                    }
                }
            }
            cout << ans.fi << " " << ans.se << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
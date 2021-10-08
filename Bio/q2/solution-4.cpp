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

double a[1000005], b[100005], c[100005], t[100005];
pii tans[100005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("4.txt");
    ofstream cout("4out.txt");
    int tc;
    cin >> tc;
    while (tc--) {
        int m,k,n;
        cin >> m >> k >> n;
        for (int i=1;i<=m;i++) cin >> a[i];
        for (int i=1;i<=k;i++) cin >> b[i];
        for (int i=1;i<=n;i++) cin >> c[i];
        for (int i=1;i<=n;i++) t[i] = 1e8;
        for (int p = 0; p <= m; p += 10000) {
            cerr << p << endl;
            vector<pair<double, pii>> v;
            for (int i = 1 + p; i <= min(m, p + 10000); i++) {
                for (int j = 1; j <= k; j++) {
                    if ((a[i] + b[j]) > 0) v.pb({a[i] + b[j], {i, j}});
                }
            }
            sort(v.begin(), v.end());
            for (int k = 1; k <= n; k++) {
                pair<double, pii> ans;
                if (c[k] <= v[0].fi) {
                    ans = v[0];
                } else if (c[k] >= v[v.size() - 1].fi) {
                    ans = v[v.size() - 1];
                } else {
                    int l = 0, r = v.size() - 1;
                    while (l <= r) {
                        int mid = (l + r) / 2;
                        if (c[k] == v[mid].fi) {
                            ans = v[mid];
                            break;
                        } else if (c[k] < v[mid].fi) {
                            if (mid > 0 && c[k] > v[mid - 1].fi) {
                                if (abs(c[k] - v[mid].fi) < abs(c[k] - v[mid - 1].fi)) {
                                    ans = v[mid];
                                } else {
                                    ans = v[mid - 1];
                                }
                                break;
                            } else {
                                r = mid - 1;
                            }
                        } else {
                            if (mid < v.size() - 1 && c[k] < v[mid + 1].fi) {
                                if (abs(c[k] - v[mid].fi) < abs(c[k] - v[mid + 1].fi)) {
                                    ans = v[mid];
                                } else {
                                    ans = v[mid + 1];
                                }
                                break;
                            } else {
                                l = mid + 1;
                            }
                        }
                    }
                }
                if (abs(ans.fi - c[k]) < t[k]) {
                    t[k] = abs(ans.fi - c[k]);
                    tans[k] = ans.se;
                }
            }
            v.clear();
        }
        for (int i = 1; i <= n; i++) cout << tans[i].fi << " " << tans[i].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
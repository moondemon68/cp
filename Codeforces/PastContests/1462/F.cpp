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

const int MAXN = 400000;
int l[MAXN + 5], r[MAXN + 5];
unordered_map<int,int> comp;
set<int> s;
int cl[MAXN + 5], cr[MAXN + 5];

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
        for (int i=1;i<=n;i++) {
            cin >> l[i] >> r[i];
            s.insert(l[i]);
            s.insert(r[i]);
        }
        int cnt = 1;
        for (int i=1;i<=n;i++) {
            cl[i] = l[i];
            cr[i] = r[i];
        }
        sort(cl+1,cl+n+1);
        sort(cr+1,cr+n+1);
        int ansv = 0;
        for (int i=1;i<=n;i++) {
            // int cur = cl[comp[r[i]]] + cr[cnt] - cr[comp[l[i]] - 1];
            int cur = 0;
            int lo = 1, hi = n, ans = 0;
            while (lo <= hi) {
                int m = (lo + hi) / 2;
                if (cl[m] <= r[i]) {
                    ans = m;
                    lo = m + 1;
                } else {
                    hi = m - 1;
                }
            }
            cur += ans;
            // cout << ans << " ";
            lo = 1, hi = n, ans = 0;
            while (lo <= hi) {
                int m = (lo + hi) / 2;
                if (cr[m] < l[i]) {
                    ans = m;
                    lo = m + 1;
                } else {
                    hi = m - 1;
                }
            }
            cur += n - ans;
            // cout << n - ans << endl;
            ansv = max(ansv, cur);
        }
        cout << 2 * n - ansv << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
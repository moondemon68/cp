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

int dp[2][200005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,q;
    cin >> n >> q;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    set<LL> s;
    map<LL, LL> cnt;
    for (LL i=1;i<=n;i++) {
        for (LL j=i+1;j<=n;j++) {
            LL p = 0;
            p += (a[i] + a[j] - 1)/__gcd(a[i], a[j]);   // sebelum a + b
            LL x = 0;
            LL u = a[i] * a[j] - a[i] - a[j];
            LL lcm = (a[i] * a[j] / __gcd(a[i], a[j]));
            x = u - u/a[i] - u/a[j] + u/lcm;
            if (lcm < (a[i] + a[j])) x = 0;
            LL ans = 1e12 / __gcd(a[i], a[j]) - p - x;
            // cout << i << " " << j <<  " " << ans << " " << p << " " << u << " " << x << endl;
            cnt[ans]++;
            s.insert(ans);
        }
    }
    vector<int> v;
    for (auto x : s) {
        v.pb(cnt[x]);
    }
    // for (auto x : v) cout << x << " ";
    sort(v.begin(), v.end());
    memset (dp,-1,sizeof(dp));
    for (int i=0;i<=v.size();i++) {
        for (int j=0;j<=n*n/2;j++) {
            if (j == 0) dp[i%2][j] = 1;
            else if (i == 0) dp[i%2][j] = 0;
            else if (v[i-1] <= j) dp[i%2][j] = dp[(i+1)%2][j-v[i-1]] | dp[(i+1)%2][j];
            else dp[i%2][j] = dp[(i+1)%2][j];
        }
    }
    while (q--) {
        int x;
        cin >> x;
        // cout << x << " " << dp[(v.size())%2][x] << endl;
        if (dp[v.size() % 2][x] == 1) cout << "YES" << endl; else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
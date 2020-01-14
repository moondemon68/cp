#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int solve(vector<int> a, int x) {
    // cout << a.size();
    if (a.size() == 0 || x < 0) return 0;
    vector<int> o,z;
    for (int i=0;i<a.size();i++) {
        if (((a[i]>>x) & 1) == 0) z.pb(a[i]); else o.pb(a[i]);
    }
    if (o.empty()) return solve(z, x-1);
    if (z.empty()) return solve(o, x-1);
    return min(solve(z, x-1), solve(o, x-1))+(1<<x);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    cout << solve(a, 30) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
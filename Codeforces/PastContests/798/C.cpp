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
    for (int i=1;i<=n;i++) cin >> a[i];
    int gcd = a[1];
    for (int i=1;i<=n;i++) gcd = __gcd(gcd, a[i]);
    if (gcd > 1) {
        cout << "YES" << endl << 0 << endl;
    } else {
        int cnt = 0;
        vector<int> v;
        int ans = 0;
        for (int i=1;i<=n;i++) {
            if (a[i] % 2 == 1) {
                cnt++;
                if (i < n && a[i+1] % 2 == 1) {
                    ans++;
                    a[i+1] = 0;
                } else {
                    v.pb(i);
                }
            }
        }
        cout << "YES" << endl;
        // for (int i=0;i<v.size();i++) {
        //     ans += 2;
        // }
        ans += v.size() * 2;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
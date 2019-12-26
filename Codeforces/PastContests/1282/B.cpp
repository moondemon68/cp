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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,p,k;
        cin >> n >> p >> k;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        int ans = 0;
        int p2 = p, ans2=0;
        if (a[1] <= p2) {
            p2 -= a[1];
            ans2++;
        }
        for (int i=3;i<=n;i+=2) {
            if (a[i] <= p2) {
                p2 -= a[i];
                ans2+=2;
            } else if (a[i-1] <= p2) {
                p2 -= a[i-1];
                ans2++;
            }
        }
        for (int i=2;i<=n;i+=2) {
            if (a[i] <= p) {
                p -= a[i];
                ans += 2;
            } else if (a[i-1] <= p) {
                p -= a[i-1];
                ans++;
            }
        }
        cout << max(ans, ans2) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
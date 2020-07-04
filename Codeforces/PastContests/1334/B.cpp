#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
        int n;
        cin >> n;
        LL x;
        cin >> x;
        LL a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        reverse(a+1,a+n+1);
        LL t = 0;
        int ans = 0;
        for (int i=1;i<=n;i++) {
            t += a[i];
            if (t >= x*i) ans = i;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
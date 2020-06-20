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
    int ans = 0;
    int b[n+5];
    for (int i=0;i<=30;i++) {
        for (int j=1;j<=n;j++) {
            if (a[j] <= i) b[j] = a[j];
            else b[j] = -1e6;
        }
        int p = 0, cur = 0;
        for (int j=1;j<=n;j++) {
            cur += b[j];
            p = max(p, cur);
            if (cur < 0) cur = 0;
        }
        ans = max(ans, p-i);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
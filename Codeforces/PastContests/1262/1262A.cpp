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
        int n;
        cin >> n;
        int a[n+5],b[n+5];
        for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int mini=INT_MAX, maxi = 0;
        for (int i=1;i<=n;i++) {
            mini = min(mini, b[i]);
            maxi = max(maxi, a[i]);
        }
        cout << max(0, maxi-mini) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
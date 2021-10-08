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
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int start = -1, end = -1;
        for (int i=1;i<=n;i++) {
            if (a[i] == 01) {
                start = i;
                break;
            }
        }
        for (int i=n;i>=1;i--) {
            if (a[i] == 1) {
                end = i;
                break;
            }
        }
        int ans = 0;
        for (int i=start;i<=end;i++) {
            if (a[i] == 0) ans++;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
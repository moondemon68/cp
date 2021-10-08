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
        sort(a+1,a+n+1);
        if (n == 2) {
            cout << a[1] << " " << a[2] << endl;
            continue;
        }
        int mindiff = INT_MAX;
        for (int i=1;i<n;i++) {
            mindiff = min(mindiff, a[i+1]-a[i]);
        }
        int ans[n+5];
        int p = 0;
        for (int i=n;i>1;i--) {
            if ((a[i] - a[i-1]) == mindiff) {
                ans[1] = a[i-1];
                ans[n] = a[i];
                p = i;
                break;
            }
        }
        int k = 2;
        for (int i=p+1;i<=n;i++) {
            ans[k] = a[i];
            k++;
        }
        for (int i=1;i<p-1;i++) {
            ans[k] = a[i];
            k++;
        }
        for (int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
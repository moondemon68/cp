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
        int m;
        cin >> m;
        int b[m+5];
        for (int i=1;i<=m;i++) cin >> b[i];
        int ans = 0, ansa = max(0, a[1]), ansb = max(0, b[1]);
        for (int i=2;i<=n;i++) {
            a[i] += a[i-1];
            ansa = max(ansa, a[i]);
        }
        for (int i=2;i<=m;i++) {
            b[i] += b[i-1];
            ansb = max(ansb, b[i]);
        }
        cout << ansa + ansb << endl;
        
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
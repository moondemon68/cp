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
        int n,m;
        cin >> n >> m;
        int a[n+5][m+5];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) cin >> a[i][j];
        }
        int b[n+5][m+5];
        memset (b,0,sizeof(b));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                int cnt = 0;
                if ((i+1 <= n)) cnt++;
                if ((i-1 >= 1) ) cnt++;
                if ((j+1 <= m) ) cnt++;
                if ((j-1 >= 1) ) cnt++;
                b[i][j] = cnt;
            }
        }
        bool y = 1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (b[i][j] < a[i][j]) y = 0;
            }
        }
        if (y) {
            cout << "YES" << endl;
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=m;j++) {
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
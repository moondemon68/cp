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
            for (int j=1;j<=m;j++) {
                cin >> a[i][j];
            }
        }
        int x = 0;
        for (int i=1;i<=n;i++) {
            bool y = 1;
            for (int j=1;j<=m;j++) {
                if (a[i][j] == 1) y = 0;
            }
            if (y) x++;
        }
        int x2 = 0;
        for (int i=1;i<=m;i++) {
            bool y = 1;
            for (int j=1;j<=n;j++) {
                if (a[j][i] == 1) y = 0;
            }
            if (y) x2++;
        }
        if (min(x, x2) % 2 == 0) cout << "Vivek" << endl;
        else cout << "Ashish" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
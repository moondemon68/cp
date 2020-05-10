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
        char a[105][105];
        int n,m;
        cin >> n >> m;
        for (int i=1;i<=n;i++) {
            if (i%2==1) {
                for (int j=1;j<=m;j++) {
                    if (j%2==1) a[i][j] = 'B'; else a[i][j] = 'W';
                }
            } else {
                for (int j=1;j<=m;j++) {
                    if (j%2 == 1) a[i][j] = 'W'; else a[i][j] = 'B';
                }
            }
        }
        if ((n*m)%2 == 0) {
            for (int i=1;i<=m;i++) {
                if (a[1][i] == 'W') {
                    a[1][i] = 'B';
                    break;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
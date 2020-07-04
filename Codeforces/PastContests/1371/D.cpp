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
        int n,k;
        cin >> n >> k;
        int a[n+5][n+5];
        memset (a,0,sizeof(a));
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (k) {
                    k--;
                    a[j][(j+i)%n] = 1;
                }
            }
        }
        int r[n+5], c[n+5];
        memset (r,0,sizeof(r));
        memset (c,0,sizeof(c));
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                r[i] += a[i][j];
                c[i] += a[j][i];
            }
        }
        sort (r,r+n);
        sort (c,c+n);
        cout << (r[n-1]-r[0]) * (r[n-1]-r[0]) + (c[n-1]-c[0]) * (c[n-1]-c[0]) << endl;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
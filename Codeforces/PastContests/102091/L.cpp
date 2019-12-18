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
        int r,c;
        cin >> r >> c;
        int a[r+5][c+5];
        memset (a,0,sizeof(a));
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                cin >> a[i][j];
            }
        }
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                a[i][j]+=a[i][j-1];
            }
        }
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                a[i][j]+=a[i-1][j];
            }
        }
        // for (int i=1;i<=r;i++) {
        //     for (int j=1;j<=c;j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int l=1,h=2000,ans=1;
        while (l<=h) {
            int m = (l+h)/2;
            bool y=0;
            for (int i=1;i<=r-m;i++) {
                for (int j=1;j<=c-m;j++) {
                    int x = a[i+m][j+m]+a[i-1][j-1]-a[i-1][j+m]-a[i+m][j-1];
                    if (x<=1) {
                        y = 1;
                    }
                    if (y) break;
                }
                if (y) break;
            }
            if (y) {
                l=m+1;
                ans=m;
            } else {
                h=m-1;
            }
        }
        cout << ans+1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
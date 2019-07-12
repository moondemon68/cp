#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL r,c;
    cin >> r >> c;
    LL a[r+5][c+5];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            cin >> a[i][j];
        }
    }
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            a[i][j]+=a[i][j-1];
        }
    }
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            a[i][j]+=a[i-1][j];
        }
    }
    /*for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
    LL ans=-1234567890;
    for (LL i=1;i<=r;i++) {
        for (LL j=1;j<=c;j++) {
            for (LL k=i;k<=r;k++) {
                for (LL l=j;l<=c;l++) {
                    //cout << i << j << k << l << " " << a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1] << endl;
                    ans=max(ans,a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1]);
                }
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n;
    cin >> n;
    int a[n+5][n+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    for (int j=1;j<=n;j++) {
        int maxi = a[1][j];
        int ans = 1;
        for (int i=2;i<=n;i++){
            if (a[i][j] > maxi) {
                maxi = a[i][j];
                ans++;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    for (int i=1;i<=n;i++) {
        int maxi = a[i][1];
        int ans = 1;
        for (int j=2;j<=n;j++){
            if (a[i][j] > maxi) {
                maxi = a[i][j];
                ans++;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
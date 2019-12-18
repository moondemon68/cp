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
    int n;
    cin >> n;
    LL a[n+5][n+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cin >> a[i][j];
    }
    LL ans=0;
    ans = a[1][2]*a[1][3]/a[2][3];
    ans = sqrt(ans);
    cout << ans << " ";
    for (int i=2;i<=n;i++) cout << a[1][i]/ans << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
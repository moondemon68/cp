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
        for (int i=1;i<=r;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=c;j++) {
                if (s[j-1] == 'R') a[i][j] = 1; else a[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i=1;i<r;i++) {
            if (a[i][c] == 1) ans++;
        }
        for (int i=1;i<c;i++) {
            if (a[r][i] == 0) ans++;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
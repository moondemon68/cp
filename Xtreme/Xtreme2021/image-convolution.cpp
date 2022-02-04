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
        int r, c;
        cin >> r >> c;
        char a[r+5][c+5];
        for (int i=1;i<=r;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=c;j++) {
                a[i][j] = s[j-1];
            }
        }
        int r2, c2;
        cin >> r2 >> c2;
        char b[r2+5][c2+5];
        for (int i=1;i<=r2;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=c2;j++) {
                b[i][j] = s[j-1];
            }
        }

        int ans = 0;
        for (int i=1;i<=r-r2+1;i++) {
            for (int j=1;j<=c-c2+1;j++) {
                bool y = 1;
                for (int k=1;k<=r2;k++) {
                    for (int l=1;l<=c2;l++) {
                        char img = a[i+k-1][j+l-1];
                        char pat = b[k][l];
                        if (img != pat && pat != '?') {
                            y = 0;
                        }
                    }
                }
                if (y) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    while (tc--) {
        int n;
        cin >> n;
        char ans[n+5][n+5];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                ans[i][j] = '?';
            }
        }
        if (n == 2) cout << "impossible" << endl;
        else if (n == 3) cout << "impossible" << endl;
        else if (n % 2 == 0) {
            int k = 0;
            for (int i=1;i<=n;i++) ans[1][i] = s[k];
            k++;
            for (int i=1;i<=n/2;i++) {
                for (int j=2;j<=n-i+1;j++) {
                    ans[j][i] = s[k];
                }
                if (i != n/2) {
                    for (int j=n-i+1;j<=n;j++) {
                        ans[j][i+1] = s[k];
                    }
                    k++;
                }
            }
            for (int i=n/2+1;i<=n;i++) {
                for (int j=2;j<=i;j++) {
                    ans[j][i] = s[k];
                }
                if (i != n/2+1) {
                    for (int j=i;j<=n;j++) {
                        ans[j][i-1] = s[k];
                    }
                }
                k++;
            }
        } else {
            int k = 0;
            for (int i=1;i<=n;i++) ans[1][i] = s[k];
            k++;
            for (int i=1;i<=n/2;i++) {
                for (int j=2;j<=n-i+1;j++) {
                    ans[j][i] = s[k];
                }
                if (i != n/2) {
                    for (int j=n-i+1;j<=n;j++) {
                        ans[j][i+1] = s[k];
                    }
                    k++;
                }
            }
            for (int i=n/2+1;i<=n;i++) {
                for (int j=2;j<=i;j++) {
                    ans[j][i] = s[k];
                }
                if (i != n/2+1) {
                    for (int j=i;j<=n;j++) {
                        ans[j][i-1] = s[k];
                    }
                }
                k++;
            }
        }

        if (n > 3) {
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
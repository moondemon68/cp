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
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        int ans = -1, ansi = -1;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        a[0] = -1;
        a[n+1] = -1;
        for (int i=1;i<=n;i++) {
            if (a[i] == 1) {
                int x = 1;
                for (int j=i;j<=n+1;j++) {
                    if (a[j] != x) {
                        if (ans < x-1) {
                            ans = x-1;
                            ansi = j-2;
                        } else if (ans == x-1) {
                            ans = x-1;
                            ansi = min(ansi, j-2);
                        }
                        break;
                    }
                    x++;
                }
                x = 1;
                for (int j=i;j>=0;j--) {
                    if (a[j] != x) {
                        if (ans < x-1) {
                            ans = x-1;
                            ansi = j;
                        } else if (ans == x-1) {
                            ans = x-1;
                            ansi = min(ansi, j);
                        }
                        break;
                    }
                    x++;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << " " << ansi << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
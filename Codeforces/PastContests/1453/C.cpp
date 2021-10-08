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

const int N = 2000;
int l[10][N+5], r[10][N+5], top[10], bot[10];
int l2[10][N+5], r2[10][N+5], top2[10], bot2[10];
int a[N+5][N+5], b[N+5][N+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=n;j++) {
                a[i][j] = s[j-1] - '0';
                b[j][i] = s[j-1] - '0';
            }
        }
        for (int i=0;i<10;i++) {
            for (int j=1;j<=n;j++) {
                l[i][j] = INT_MAX;
                l2[i][j] = INT_MAX;
                r[i][j] = INT_MIN;
                r2[i][j] = INT_MIN;
            }
            top[i] = INT_MIN;
            top2[i] = INT_MIN;
            bot[i] = INT_MAX;
            bot2[i] = INT_MAX;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                l[a[i][j]][i] = min(l[a[i][j]][i], j);
                l2[b[i][j]][i] = min(l2[b[i][j]][i], j);
                r[a[i][j]][i] = max(r[a[i][j]][i], j);
                r2[b[i][j]][i] = max(r2[b[i][j]][i], j);
                top[a[i][j]] = max(top[a[i][j]], i);
                top2[b[i][j]] = max(top2[b[i][j]], i);
                bot[a[i][j]] = min(bot[a[i][j]], i);
                bot2[b[i][j]] = min(bot2[b[i][j]], i);
            }
        }
        for (int d=0;d<=9;d++) {
            int ans = 0;
            for (int i=1;i<=n;i++) {
                if (l[d][i] == INT_MAX) continue;   // no digit in that row
                for (int j=1;j<=n;j++) {
                    ans = max(ans, (abs(j - l[d][i])) * abs(i - top[d]));
                    ans = max(ans, (abs(j - r[d][i])) * abs(i - top[d]));
                    ans = max(ans, (abs(l[d][i] - r[d][i])) * (i - 1));
                    ans = max(ans, (abs(j - l[d][i])) * abs(i - bot[d]));
                    ans = max(ans, (abs(j - r[d][i])) * abs(i - bot[d]));
                    ans = max(ans, (abs(l[d][i] - r[d][i])) * (n - i));
                }
            }
            for (int i=1;i<=n;i++) {
                if (l2[d][i] == INT_MAX) continue;   // no digit in that row
                for (int j=1;j<=n;j++) {
                    ans = max(ans, (abs(j - l2[d][i])) * abs(i - top2[d]));
                    ans = max(ans, (abs(j - r2[d][i])) * abs(i - top2[d]));
                    ans = max(ans, (abs(l2[d][i] - r2[d][i])) * (i - 1));
                    ans = max(ans, (abs(j - l2[d][i])) * abs(i - bot2[d]));
                    ans = max(ans, (abs(j - r2[d][i])) * abs(i - bot2[d]));
                    ans = max(ans, (abs(l2[d][i] - r2[d][i])) * (n - i));
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
// 100 mins
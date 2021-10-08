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
    // ifstream cin("E.in");
    // ofstream cout("E.out");
    int d,h,l;
    cin >> d >> h >> l;
    int a[d+5][h+5][l+5];
    for (int i=1;i<=d;i++) {
        for (int j=1;j<=h;j++) {
            for (int k=1;k<=l;k++) {
                cin >> a[i][j][k];
            }
        }
    }
    int dd[h+5][l+5];
    int ans = 0;
    for (int i=1;i<=d;i++) {
        for (int j=1;j<=h;j++) {
            for (int k=1;k<=l;k++) {
                dd[j][k] = 1;
            }
        }
        for (int j=i;j<=d;j++) {
            for (int k=1;k<=h;k++) {
                for (int m=1;m<=l;m++) {
                    dd[k][m] &= a[j][k][m];
                }
            }
            int area = 0;
            int dp[h+5][l+5];
            memset(dp,0,sizeof(dp));
            for (int k=1;k<=h;k++) {
                for (int m=1;m<=l;m++) {
                    if (dd[k][m] == 1) {
                        dp[k][m] = 1 + dp[k][m-1];
                    } else {
                        dp[k][m] = 0;
                    }
                    // cout << dp[k][m] << " ";
                }
                // cout << endl;
            }
            for (int k=1;k<=l;k++) {
                stack<int> s;
                int maxi = 0;
                int m = 0;
                while (m <= h) {
                    if (s.empty() || dp[s.top()][k] <= dp[m][k]) {
                        s.push(m++);
                    } else {
                        int tp = s.top();
                        s.pop();
                        int atp = dp[tp][k] * (s.empty() ? m : m - s.top() - 1);
                        maxi = max(maxi, atp);
                    }
                }
                while (!s.empty()) {
                    int tp = s.top();
                    s.pop();
                    int atp = dp[tp][k] * (s.empty() ? m : m - s.top() - 1);
                    maxi = max(maxi, atp);
                }
                // cout << maxi << endl;
                area = max(area, maxi);
            }

            // cout << i << " " << j << " " << area << endl << endl;

            int local = (j - i + 1) * area;
            ans = max(ans, local);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
3 6 6
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 0 0 0 0 0
1 0 1 1 1 1
1 0 1 1 1 1
1 0 1 1 1 1
1 0 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
0 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
*/
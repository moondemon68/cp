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

LL a[3005][3005];
LL dp[3005][3005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL r,c,k;
    cin >> r >> c >> k;
    for (LL i=1;i<=k;i++) {
        LL x,y,v;
        cin >> x >> y >> v;
        a[x][y] = v;
    }
    for (LL i=1;i<=r;i++) {
        priority_queue<pii, vector<pii>, greater<pii>> p;
        LL x = 0;
        for (LL j=1;j<=c;j++) {
            // cout << a[i][j] << " ";
            if (a[i][j] == 0) {
                dp[i][j] = x;
            } else {
                x += a[i][j];
                p.push({a[i][j], j});
            }
            if (i > 1) {
                pii tmp1 = {0,0}, tmp2 = {0,0}, tmp3 = {0,0}, tmp4 = {0,0};
                if (!p.empty()) tmp1 = p.top();
                p.pop();
                if (!p.empty()) tmp2 = p.top();
                p.pop();
                if (!p.empty()) tmp3 = p.top();
                p.pop();
                if (!p.empty()) tmp4 = p.top();
                p.pop();
                if (tmp1.se != 0) dp[i][j] = max(x - tmp1.fi + dp[i-1][max(tmp4.se, max(tmp2.se, tmp3.se))], dp[i-1][j] + a[i][j]);
                if (tmp2.se != 0) dp[i][j] = max(x - tmp2.fi + dp[i-1][max(tmp1.se, max(tmp4.se, tmp3.se))], dp[i-1][j] + a[i][j]);
                if (tmp3.se != 0) dp[i][j] = max(x - tmp3.fi + dp[i-1][max(tmp1.se, max(tmp2.se, tmp4.se))], dp[i-1][j] + a[i][j]);
                if (tmp4.se != 0) dp[i][j] = max(x - tmp4.fi + dp[i-1][max(tmp1.se, max(tmp2.se, tmp3.se))], dp[i-1][j] + a[i][j]);
                if (tmp1.se != 0) p.push(tmp1);
                if (tmp2.se != 0) p.push(tmp2);
                if (tmp3.se != 0) p.push(tmp3);
                if (tmp4.se != 0) p.push(tmp4);
                if (p.size() == 4) p.pop();
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[r][c] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
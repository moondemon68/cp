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
    LL n,m;
    cin >> n >> m;
    char a[n+5][m+5];
    for (LL i=0;i<n;i++) {
        string s;
        cin >> s;
        for (LL j=0;j<m;j++) {
            a[i][j] = s[j];
        }
    }

    LL up[n+5][m+5], left[n+5][m+5];
    for (LL i=0;i<n;i++) {
        for (LL j=0;j<m;j++) {
            up[i][j] = 1;
            if (i > 0 && a[i][j] == a[i-1][j]) up[i][j] = up[i-1][j] + 1;
            left[i][j] = 1;
            if (j > 0 && a[i][j] == a[i][j-1]) left[i][j] = left[i][j-1] + 1;
        }
    }

    LL down[n+5][m+5], right[n+5][m+5];
    for (LL i=n-1;i>=0;i--) {
        for (LL j=m-1;j>=0;j--) {
            down[i][j] = 1;
            if (i < n-1 && a[i][j] == a[i+1][j]) down[i][j] = down[i+1][j] + 1;
            right[i][j] = 1;
            if (j < m-1 && a[i][j] == a[i][j+1]) right[i][j] = right[i][j+1] + 1;
        }
    }

    for (int i=1;i<n;i++) {
        for (int j=1;j<m;j++) {
            up[i][j] = min(up[i][j], left[i][j]);
            up[i][j] = min(up[i][j], up[i-1][j-1]+2);
            if (a[i][j] != a[i-1][j-1]) up[i][j] = min(up[i][j], 2LL);
        }
    }
    for (int i=1;i<n;i++) {
        for (int j=m-2;j>=0;j--) {
            up[i][j] = min(up[i][j], right[i][j]);
            up[i][j] = min(up[i][j], up[i-1][j+1]+2);
            if (a[i][j] != a[i-1][j+1]) up[i][j] = min(up[i][j], 2LL);
        }
    }
    for (int i=n-2;i>=0;i--) {
        for (int j=1;j<m;j++) {
            down[i][j] = min(down[i][j], left[i][j]);
            down[i][j] = min(down[i][j], down[i+1][j-1]+2);
            if (a[i][j] != a[i+1][j-1]) down[i][j] = min(down[i][j], 2LL);
        }
    }
    for (int i=n-2;i>=0;i--) {
        for (int j=m-2;j>=0;j--) {
            down[i][j] = min(down[i][j], right[i][j]);
            down[i][j] = min(down[i][j], down[i+1][j+1]+2);
            if (a[i][j] != a[i+1][j+1]) down[i][j] = min(down[i][j], 2LL);
        }
    }

    LL ans = 0;
    for (LL i=0;i<n;i++) {
        for (LL j=0;j<m;j++) {
            int x = min(up[i][j], left[i][j]);
            int y = min(down[i][j], right[i][j]);
            ans += min(x, y);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

/*
5 5
aabaa
aabaa
bbbbb
aabaa
aabaa
*/
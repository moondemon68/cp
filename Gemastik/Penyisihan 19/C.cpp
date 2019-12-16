#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int x, y, m, n;

int k[N * N + 5];
int g[N][N];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);
    x = (s[0] - '0');
    y = (s[2] - '0');
    getline(cin, s);
    if ((int) s.size() == 2) m = 10;
    else m = (s[0] - '0');
    getline(cin, s);
    int len = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '0') {
            k[len] = 0;
        } else if (s[i] == '1') {
            k[len] = 1;
        }
        len++;
    }
    n = len;
    for (int i = 0; i < n; i++) {
        g[0][i]=k[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    long long cnt[n+5][n+5][m+5];
    memset (cnt,0,sizeof(cnt));
    for (int e=0;e<=m;e++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cnt[i][j][e]=0;
                if (e==0&&i==j) cnt[i][j][e]=1;
                if (e==1&&g[i][j]) cnt[i][j][e]=1;
                if (e>1) {
                    for (int a=1;a<=n;a++) {
                        if (g[i][a]) cnt[i][j][e]+=cnt[a][j][e-1];
                    }
                }
            }
        }
    }
    cout << cnt[x][y][m] << endl;
    return 0;
}
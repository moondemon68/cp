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
    int n,m;
    cin >> n >> m;
    bool trans = 0;
    if (m % 2 != 0) {
        trans = 1;
        swap(n, m);
    }
    int a[n+5][m+5];
    bool y = 0;
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (y) {
            for (int j=1;j<=m;j++) {
                a[i][j] = (j % 2 == 0);
            }
        } else {
            for (int j=1;j<=m;j++) {
                a[i][j] = (j % 2 == 1);
            }
        }
        cnt++;
        if (cnt == 2) {
            y = !y;
            cnt = 0;
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    queue<pii> x, o;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] == 0) {
                o.push({i, j});
            } else {
                x.push({i, j});
            }
        }
    }
    int tot = n * m;
    while (tot--) {
        char c;
        cin >> c;
        if (c == 'X') {
            if (trans) {
                cout << x.front().se << " " << x.front().fi << endl;
            } else {
                cout << x.front().fi << " " << x.front().se << endl;
            }
            x.pop();
        } else {
            if (trans) {
                cout << o.front().se << " " << o.front().fi << endl;
            } else {
                cout << o.front().fi << " " << o.front().se << endl;
            }
            o.pop();
        }
        cout << flush;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
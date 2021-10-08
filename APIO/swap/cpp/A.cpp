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
    int r,c;
    cin >> r >> c;
    string s[r+5];
    for (int i=1;i<=r;i++) cin >> s[i];
    int q;
    cin >> q;
    int a[r+5][c+5];
    memset (a,0,sizeof(a));
    while (q--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x1][y2+1]--;
        a[x2+1][y1]--;
        a[x2+1][y2+1]++;
    }
    int d[r+5][c+5];
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            d[i][j] = a[i][j];
        }
    }
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            a[i][j] += a[i][j-1];
        }
    }
    for (int i=1;i<=c;i++) {
        for (int j=1;j<=r;j++) {
            a[j][i] += a[j-1][i];
        }
    }
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if ((a[i-1][j] + a[i][j-1] - a[i-1][j-1] + d[i][j]) % 2 == 0) {
                cout << s[i][j-1];
            } else {
                if (s[i][j-1] == '0') cout << 1;
                else cout << 0;
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
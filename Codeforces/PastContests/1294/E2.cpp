#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
    int a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=1;i<=c;i++) {
        int p[2*r+5];
        memset (p,0,sizeof(p));
        for (int j=1;j<=r;j++) {
            if (a[j][i] % c != (i%c)) continue;
            p[j] = a[j][i]/c + 1;
            if (i == c) p[j]--;
        }
        // for (int j=1;j<=r;j++) {
        //     cout << p[j] << " ";
        // }
        // cout << endl;
        int cnt[r+5];
        for (int j=1;j<=r;j++) cnt[j] = r;
        for (int j=1;j<=r;j++) {
            if (p[j] == 0) {
                // cnt[j] = MOD;
                continue;
            }
            int x=j-p[j];
            if (x < 0) x += r;
            if (x >= 0 && x <= r) cnt[x]--;
        }
        // for (int j=1;j<=r;j++) {
        //     cout << cnt[j] << " ";
        // }
        // cout << endl;
        // cout << "===" << endl;
        int add = 0;
        for (int j=1;j<=r;j++) {
            if (j != p[j]) add++;
        }
        for (int j=1;j<=r;j++) {
            add = min(add, cnt[j]+j);
        }
        ans += add;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
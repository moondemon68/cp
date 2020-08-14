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
    int a[n+5],b[m+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int j=1;j<=m;j++) cin >> b[j];
    int ans = 0;
    int p[n+5][m+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            p[i][j] = (a[i]&b[j]);
            // cout << p[i][j] << " ";
        }
        // cout << endl;
    }
    bool done[n+5];
    memset (done,0,sizeof(done));
    int maxi = 0;
    for (int i=1;i<=n;i++) {
        int mini = INT_MAX;
        for (int j=1;j<=m;j++) {
            mini = min(mini, p[i][j]);
        }
        maxi = max(mini, maxi);
    }
    ans = maxi;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (p[i][j] == 0) done[i] = 1;
            if (p[i][j] > ans) continue;
            bool udah = 1;
            for (int k=0;k<=9;k++) {
                if (!(bool)(p[i][j]&(1<<k)) && (bool)(ans&(1<<k))) {
                    udah = 0;
                    break;
                }
            }
            if (udah) done[i] = 1;
            if (done[i]) break;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int k=0;k<=9;k++) {
                if ((bool)(p[i][j]&(1<<k)) && (bool)(ans&(1<<k))) {
                    p[i][j] -= (1<<k);
                }
            }
        }
    }
    // cout << ans << endl;
    while (1) {
        bool semua = 1;
        for (int i=1;i<=n;i++) {
            if (!done[i]) semua = 0;
            // else cout << i << " ";
        }
        // cout << endl;
        if (semua) break;

        maxi = 0;
        for (int i=1;i<=n;i++) {
            if (done[i]) continue;
            int mini = INT_MAX;
            for (int j=1;j<=m;j++) {
                mini = min(mini, p[i][j]);
            }
            maxi = max(mini, maxi);
        }

        if (maxi == 0) break;
        ans += maxi;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (p[i][j] == 0) done[i] = 1;
                if (p[i][j] > ans) continue;
                bool udah = 1;
                for (int k=0;k<=9;k++) {
                    if (!(bool)(p[i][j]&(1<<k)) && (bool)(ans&(1<<k))) {
                        udah = 0;
                        break;
                    }
                }
                if (udah) done[i] = 1;
                if (done[i]) break;
            }
        }

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                for (int k=0;k<=9;k++) {
                    if ((bool)(p[i][j]&(1<<k)) && (bool)(ans&(1<<k))) {
                        p[i][j] -= (1<<k);
                    }
                }
            }
        }
        // cout << ans << endl;
    }
    // for (int i=1;i<=n;i++) {
    //     if (!done[i]) {
    //         for (int j=1;j<=m;j++) cout << p[i][j] << " ";
    //         cout << endl;   
    //     }
    // }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
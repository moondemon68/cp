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
    ifstream cin("02");
    ofstream cout("02.out");
    int tc;
    cin >> tc;
    while (tc--) {
        int n, l;
        cin >> n >> l;
        bool mut[n+5];
        string a[n+5];
        double neg = 0, pos = 0;
        for (int i=1;i<=n;i++) {
            char c;
            cin >> c;
            if (c == '-') {
                mut[i] = 0;
                neg+=1;
            }
            else {
                mut[i] = 1;
                pos+=1;
            }
            cin >> a[i];
        }
        // for (int i=1;i<=n;i++) {
        //     if (mut[i]) cout << a[i] << endl;
        // }
        // cout << endl;
        // for (int i=1;i<=n;i++) {
        //     if (!mut[i]) cout << a[i] << endl;
        // }
        double cnt[l+5][4];
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            if (mut[i]) {
                for (int j=0;j<l;j++) {
                    if (a[i][j] == 'A') cnt[j][0] += neg/(neg+pos);
                    if (a[i][j] == 'C') cnt[j][1] += neg/(neg+pos);
                    if (a[i][j] == 'G') cnt[j][2] += neg/(neg+pos);
                    if (a[i][j] == 'T') cnt[j][3] += neg/(neg+pos);
                }
            } else {
                for (int j=0;j<l;j++) {
                    if (a[i][j] == 'A') cnt[j][0] -= pos/(neg+pos);
                    if (a[i][j] == 'C') cnt[j][1] -= pos/(neg+pos);
                    if (a[i][j] == 'G') cnt[j][2] -= pos/(neg+pos);
                    if (a[i][j] == 'T') cnt[j][3] -= pos/(neg+pos);
                }
            }
        }
        // for (int i=0;i<l;i++) {
        //     for (int j=0;j<4;j++) {
        //         cout << cnt[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> ans;
        int limit = 3;
        while (1) {
            for (int i=0;i<l;i++) {
                int p = 0;
                for (int j=0;j<4;j++) if (cnt[i][j] < 0) p++;
                if (p >= limit) {
                    ans.pb(i);
                    // break;
                }
            }
            if (ans.size() > 0) {
                cout << ans.size() << endl;
                cout << ans[0] << " " << ans.back() << endl;
                break;
            } else {
                limit--;
            }
        }
        // cout << endl;
        // vector<int> real;
        // for (auto x : ans) {
        //     int test = 0;
        //     int p = -1, q = -1;
        //     for (int j=0;j<4;j++) {
        //         if (cnt[x][j] > 0) {
        //             if (p == -1) p = j;
        //             else q = j;
        //         }
        //     }
        //     // gaboleh ada gen yg > 0 dari yg negatif
        //     cout << cnt[x][0] << " " << cnt[x][1] << " " << cnt[x][2] << " " << cnt[x][3] << " -> ";
        //     for (int i=1;i<=n;i++) {
        //         if (!mut[i]) {
        //             int code = 0;
        //             if (a[i][x] == 'A') code = 0;
        //             if (a[i][x] == 'C') code = 1;
        //             if (a[i][x] == 'G') code = 2;
        //             if (a[i][x] == 'T') code = 3;
        //             cnt[x][code]--;
        //         }
        //     }
        //     cout << cnt[x][0] << " " << cnt[x][1] << " " << cnt[x][2] << " " << cnt[x][3] << endl;;
        // }
        // cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    ifstream cin("05");
    ofstream cout("05.out");
    int tc;
    cin >> tc;
    while (tc--) {
        int n, l;
        cin >> n >> l;
        bool mut[n+5];
        string a[n+5];
        string b[n+5];
        for (int i=1;i<=n;i++) {
            char c;
            cin >> c;
            if (c == '-') mut[i] = 0;
            else mut[i] = 1;
            cin >> a[i] >> b[i];
        }
        // for (int i=1;i<=n;i++) {
        //     if (mut[i]) cout << a[i] << endl;
        // }
        // cout << endl;
        // for (int i=1;i<=n;i++) {
        //     if (!mut[i]) cout << a[i] << endl;
        // }
        int cnt[l+5][16];
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            if (mut[i]) {
                for (int j=0;j<l;j++) {
                    int tmp = 0;
                    if (a[i][j] == 'A') tmp += 0;
                    if (a[i][j] == 'C') tmp += 1;
                    if (a[i][j] == 'G') tmp += 2;
                    if (a[i][j] == 'T') tmp += 3;
                    tmp *= 4;
                    if (b[i][j] == 'A') tmp += 0;
                    if (b[i][j] == 'C') tmp += 1;
                    if (b[i][j] == 'G') tmp += 2;
                    if (b[i][j] == 'T') tmp += 3;
                    cnt[j][tmp]++;
                }
            }
        }
        // for (int i=0;i<l;i++) {
        //     for (int j=0;j<4;j++) {
        //         cout << cnt[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "=======================================================" << endl;
        for (int i=0;i<l;i++) {
            int p = 0;
            for (int j=0;j<4;j++) {
                for (int k=0;k<4;k++) {
                    if (cnt[i][4*j+k] == 0) p++;
                }
            }
            if (p == 15) {
                cout << i << " " << i << endl;
                // break;
            }
        }

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

const int MAXN = 1000;
bool mut[MAXN+5];
string a[MAXN+5];
string b[MAXN+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("06");
    ofstream cout("06.out");
    int tc;
    cin >> tc;
    while (tc--) {
        int n, l;
        cin >> n >> l;
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
            cin >> a[i] >> b[i];
        }
        int cnt[l+5][16];
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
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
                if (mut[i]) cnt[j][tmp] += neg/(neg+pos);
                else cnt[j][tmp] -= pos/(neg+pos);
            }
        }
        // for (int i=0;i<l;i++) {
        //     for (int j=0;j<4;j++) {
        //         cout << cnt[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "=======================================================" << endl;
        vector<int> ans;
        int limit = 12;
        while (1) {
            cerr << limit << endl;
            for (int i=0;i<l;i++) {
                int p = 0;
                for (int j=0;j<4;j++) {
                    for (int k=0;k<4;k++) {
                        if (cnt[i][4*j+k] <= 0) p++;
                    }
                }
                if (p >= limit) {
                    ans.pb(i);
                    // break;
                }
            }
            if (ans.size() > 0) {
                cout << ans[0] << " " << ans.back() << endl;
                break;
            } else {
                limit--;
            }
        }
        // cout << ans[0] << " " << ans.back() << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
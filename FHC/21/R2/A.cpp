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

int cnt[1000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("A_input.txt");
    ofstream cout("A_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a, b;
        for (int i=0;i<=n;i++) {
            vector<int> v, w;
            for (int j=0;j<m;j++) {
                int x;
                cin >> x;
                v.pb(x);
                w.pb(0);
            }
            sort(v.begin(), v.end());
            a.pb(v);
            b.pb(w);
        }
        int ans = 0;
        memset(cnt,0,sizeof(cnt));
        for (int j=0;j<m;j++) {
            b[0][j] = a[0][j];
        }
        for (int i=1;i<=n;i++) {
            map<int, queue<int>> ada;
            for (int j=0;j<m;j++) {
                ada[a[i-1][j]].push(j);
            }
            queue<int> sad;
            for (int j=0;j<m;j++) {
                if (!ada[a[i][j]].empty()) {
                    int cur = ada[a[i][j]].front();
                    // cout << a[i][j] << " " << cur << " " << " : ";
                    b[i][cur] = a[i][j];
                    ada[a[i][j]].pop();
                } else {
                    sad.push(a[i][j]);
                }
            }
            // cout << "sad: " << sad.size() << endl;
            for (auto x : ada) {
                while (!x.se.empty()) {
                    cnt[x.se.front()]++;
                    b[i][x.se.front()] = sad.front();
                    x.se.pop();
                    sad.pop();
                }
            }
            for (int j=0;j<m;j++) {
                a[i][j] = b[i][j];
            }
        }
        map<int,int> xtra;
        for (int j=0;j<m;j++) {
            if (cnt[j] == 0) xtra[b[n][j]]++;
        }
        // cout << "Xtra: ";
        // for (auto x : xtra) cout << x.fi << " ";
        // cout << endl;
        // for (int j=0;j<m;j++) {
        //     cout << cnt[j] << " ";
        // }
        // cout << endl;
        for (int j=0;j<m;j++) {
            if (cnt[j] >= 2) {
                int i = n;
                while (b[i][j] == b[i-1][j]) i--;
                if (xtra[b[i-1][j]] > 0) {
                    xtra[b[i-1][j]]--;
                    cnt[j]--;
                    // cout << j << "+";
                } else {
                    while (i >= 0) {
                        if (xtra[b[i][j]] > 0) {
                            bool can = 0;
                            for (int k=i;k>0;k--) {
                                if (b[k][j] != b[k-1][j]) {
                                    can = 1;
                                    break;
                                }
                            }
                            if (can) {
                                xtra[b[i][j]]--;
                                cnt[j]--;
                                // cout << j << "+";
                                break;
                            }
                        }
                        i--;
                    }
                }
            }
        }
        // if (n <= 50) {
        //     for (int i=0;i<=n;i++) {
        //         for (int j=0;j<m;j++) {
        //             cout << b[i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        //     for (int j=0;j<m;j++) {
        //         cout << cnt[j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int j=0;j<m;j++) {
            ans += max(cnt[j]-1, 0);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
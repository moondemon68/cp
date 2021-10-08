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
    ifstream cin("xs_and_os_input.txt");
    ofstream cout("xs_and_os_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        char a[n+5][n+5];
        for (int i=1;i<=n;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=n;j++) {
                a[i][j] = s[j-1];
            }
        }
        int ans = INT_MAX;
        set<set<pii>> s;
        for (int i=1;i<=n;i++) {
            // row only X or .
            bool can = 1;
            for (int j=1;j<=n;j++) {
                if (a[i][j] == 'O') {
                    can = 0;
                    break;
                }
            }
            if (can) {
                set<pii> p;
                for (int j=1;j<=n;j++) {
                    if (a[i][j] == '.') {
                        p.insert({i, j});
                    }
                }
                if (p.size() < ans) {
                    ans = p.size();
                    s.clear();
                    s.insert(p);
                } else if (p.size() == ans) {
                    s.insert(p);
                }
            }
        }
        for (int i=1;i<=n;i++) {
            // row only X or .
            bool can = 1;
            for (int j=1;j<=n;j++) {
                if (a[j][i] == 'O') {
                    can = 0;
                    break;
                }
            }
            if (can) {
                set<pii> p;
                for (int j=1;j<=n;j++) {
                    if (a[j][i] == '.') {
                        p.insert({j, i});
                    }
                }
                if (p.size() < ans) {
                    ans = p.size();
                    s.clear();
                    s.insert(p);
                } else if (p.size() == ans) {
                    s.insert(p);
                }
            }
        }
        if (ans == INT_MAX) {
            cout << "Case #" << t << ": " << "Impossible" << endl;
        } else {
            cout << "Case #" << t << ": " << ans << " " << s.size() << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
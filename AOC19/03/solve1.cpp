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
    ifstream cin("1.in");
    ofstream cout("1.out");
    set<pii> s;
    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i=1;i<=n;i++) {
        string p;
        cin >> p;
        int m = 0;
        for (int j=1;j<p.size();j++) {
            m += p[j] - '0';
            m *= 10;
        }
        m /= 10;
        if (p[0] == 'U') {
            for (int j=1;j<=m;j++) {
                y++;
                s.insert(mp(x, y));
            }
        } else if (p[0] == 'D') {
            for (int j=1;j<=m;j++) {
                y--;
                s.insert(mp(x, y));
            }
        } else if (p[0] == 'L') {
            for (int j=1;j<=m;j++) {
                x--;
                s.insert(mp(x, y));
            }
        } else if (p[0] == 'R') {
            for (int j=1;j<=m;j++) {
                x++;
                s.insert(mp(x, y));
            }
        }
    }
    cin >> n;
    x = 0; y = 0;
    vector<int> ans;
    for (int i=1;i<=n;i++) {
        string p;
        cin >> p;
        int m = 0;
        for (int j=1;j<p.size();j++) {
            m += p[j] - '0';
            m *= 10;
        }
        m /= 10;
        if (p[0] == 'U') {
            for (int j=1;j<=m;j++) {
                y++;
                if (s.find(mp(x, y)) != s.end()) {
                    ans.pb(abs(x)+abs(y));
                }
            }
        } else if (p[0] == 'D') {
            for (int j=1;j<=m;j++) {
                y--;
                if (s.find(mp(x, y)) != s.end()) {
                    ans.pb(abs(x)+abs(y));
                }
            }
        } else if (p[0] == 'L') {
            for (int j=1;j<=m;j++) {
                x--;
                if (s.find(mp(x, y)) != s.end()) {
                    ans.pb(abs(x)+abs(y));
                }
            }
        } else if (p[0] == 'R') {
            for (int j=1;j<=m;j++) {
                x++;
                if (s.find(mp(x, y)) != s.end()) {
                    ans.pb(abs(x)+abs(y));
                }
            }
        }
    }
    sort (ans.begin(), ans.end());
    cout << ans[0] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
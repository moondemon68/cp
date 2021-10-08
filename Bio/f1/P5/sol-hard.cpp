#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

vector<pii> v[500104+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    // string testname = "0-test";
    string testname = "80-big-approx";
    ifstream cin(testname + ".txt");
    ofstream cout(testname + ".out");
    LL n, d;
    cin >> n >> d;
    for (LL i=1;i<=n;i++) {
        string s;
        cin >> s;
        s += ',';
        LL cur = 0;
        pii tmp = {-1, -1};
        for (LL j=0;j<s.size();j++) {
            if (s[j] == '-') {
                cur /= 10;
                tmp.fi = cur;
                cur = 0;
            } else if (s[j] == ',') {
                cur /= 10;
                tmp.se = cur;
                cur = 0;
                v[i].pb(tmp);
            } else {
                cur += s[j] - '0';
                cur *= 10;
            }
        }
    }
    LL q;
    cin >> q;
    while (q--) {
        if (q % 10000 == 0) cerr << q << endl;
        LL idx = -1, cnt = 0;
        string s;
        cin >> s;
        s += ',';
        LL cur = 0;
        pii tmp = {-1, -1};
        vector<pii> a;
        for (LL j=0;j<s.size();j++) {
            if (s[j] == '-') {
                cur /= 10;
                tmp.fi = cur;
                cur = 0;
            } else if (s[j] == ',') {
                cur /= 10;
                tmp.se = cur;
                cur = 0;
                a.pb(tmp);
            } else {
                cur += s[j] - '0';
                cur *= 10;
            }
        }
        LL ans = 0, mini = 1e18;
        for (LL co=1;co<=100;co++) {
            LL i = rand() % n + 1;
            LL minj = 1e18;
            for (LL j=0;j<(LL)v[i].size() - (LL)a.size() + 1;j++) {
                // cout << j << " ";
                bool y = 1;
                LL cur = 0;
                for (LL k=0;k<(LL)a.size();k++) {
                    // cout << k;
                    if (k == a.size() - 1) {
                        cur += abs(v[i][j+k].fi - a[k].fi);
                        if (a[k].se > v[i][j+k].se) cur += a[k].se - v[i][j+k].se;
                    } else if (k == 0) {
                        cur += abs(v[i][j+k].se - a[k].se);
                        if (a[k].fi < v[i][j+k].fi) cur += v[i][j+k].fi - a[k].fi;
                    } else {
                        cur += abs(v[i][j+k].fi - a[k].fi);
                        cur += abs(v[i][j+k].se - a[k].se);
                    }
                    if (cur > 1e16) continue;
                }
                if (cur < minj) {
                    minj = cur;
                }
            }
            if (minj < mini) {
                mini = minj;
                ans = i;
            }
        }
        cout << ans-1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
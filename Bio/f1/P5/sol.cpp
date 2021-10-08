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

vector<pii> v[500104+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // string testname = "0-test";
    string testname = "60-huge-inexact";
    ifstream cin(testname + ".txt");
    ofstream cout(testname + ".out");
    int n, d;
    cin >> n >> d;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        s += ',';
        int cur = 0;
        pii tmp = {-1, -1};
        for (int j=0;j<s.size();j++) {
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
    // for (int i=1;i<=n;i++) {
    //     for (int j=0;j<v[i].size();j++) {
    //         cout << v[i][j].fi << " " << v[i][j].se << ", ";
    //     }
    //     cout << endl;
    // }
    int q;
    cin >> q;
    while (q--) {
        cerr << q << endl;
        int idx = -1, cnt = 0;
        string s;
        cin >> s;
        s += ',';
        int cur = 0;
        pii tmp = {-1, -1};
        vector<pii> a;
        for (int j=0;j<s.size();j++) {
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
        for (int i=1;i<=n;i++) {
            for (int j=0;j<(int)v[i].size() - (int)a.size() + 1;j++) {
                // cout << j << " ";
                bool y = 1;
                for (int k=0;k<a.size();k++) {
                    // cout << k;
                    if (abs(v[i][j+k].fi - a[k].fi) <= d && abs(v[i][j+k].se - a[k].se) <= d) continue;
                    if (k == a.size()-1 && abs(v[i][j+k].fi - a[k].fi) <= d && a[k].se <= v[i][j+k].se) continue;
                    if (k == 0 && abs(v[i][j+k].se - a[k].se) <= d && a[k].fi >= v[i][j+k].fi) continue;
                    y = 0;
                    break;
                }
                // cout << " = ";
                if (y) {
                    // cout << "> " << i-1 << " " << j << endl;
                    if (idx == -1) idx = i;
                    cnt++;
                    break;
                }
            }
        }
        if (cnt == 0) cout << "-1 0" << endl;
        else cout << idx - 1 << " " << cnt << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
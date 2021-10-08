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

const int MAXN = 300;
const int MAXK = 10600;
int a[MAXN+5][MAXK+5], b[MAXN+5][MAXK+5], c[MAXN+5][MAXK+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("test3.txt");
    ofstream cout("test3.out");
    int n, m;
    cin >> n >> m;
    int k;
    for (int i=1;i<=n;i++) {
        string s, t;
        cin >> s >> t;
        k = s.size();
        for (int j=0;j<s.size();j++) {
            a[i][j] = s[j] - '0';
        }
        for (int j=0;j<t.size();j++) {
            b[i][j] = t[j] - '0';
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=0;j<k;j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    int cnt[10600+5][3];
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        for (int j=0;j<k;j++) {
            cnt[j][c[i][j]]++;
        }
    }
    // for (int i=0;i<k;i++) {
    //     cout << cnt[i][0] << " " << cnt[i][1] << " " << cnt[i][2] << endl;
    // }
    // gandeng 5
    vector<int> v;
    v.pb(0);
    for (int i=1;i<=k;i++) {
        v.pb(-i);
        v.pb(i);
    }

    for (int i=1;i<=m;i++) {
        cerr << i << " " << m << endl;
        string s;
        cin >> s;
        string ans = s;
        for (int j=0;j<k;j++) {
            if (s[j] == '?') {
                int known = 0;
                vector<int> p;
                for (auto l : v) {
                    if (l == 0) continue;
                    if (j+l < 0 || j+l >= k) continue;
                    if (s[j+l] == '?') continue;
                    known++;
                    p.pb(j+l);
                    if (p.size() == 5) break;
                }
                char defans = '0';
                int maxi = max(max(cnt[j][0], cnt[j][1]), cnt[j][2]);
                if (maxi == cnt[j][0]) defans = '0';
                if (maxi == cnt[j][1]) defans = '1';
                if (maxi == cnt[j][2]) defans = '2';
                if (known == 0) {
                    ans[j] = defans;
                } else {
                    int jum[3];
                    memset(jum,0,sizeof(jum));
                    for (int f=1;f<=n;f++) {
                        bool same = 1;
                        for (auto x : p) {
                            if (c[f][x] != s[x]-'0') same = 0;
                        }
                        if (same) {
                            jum[c[f][j]]++;
                        }
                    }
                    int maxj = max(max(jum[0], jum[1]), jum[2]);
                    if (maxj == jum[0]) ans[j] = '0';
                    if (maxj == jum[1]) ans[j] = '1';
                    if (maxj == jum[2]) ans[j] = '2';
                    if (maxj == 0) ans[j] = defans;
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
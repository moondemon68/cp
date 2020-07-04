#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
 
int lps[105];
 
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
		cout << "Case " << t << ":" << "\n";
        map<string,int> m;
        int cnt = 0;
        int n,q;
        cin >> n >> q;
		cin.ignore();
        vector<int> a[n+5];
        map<vector<int>, int> ans;
        for (int i=1;i<=n;i++) {
            string s;
            getline(cin, s);
            s += ' ';
            string cur = "";
            int SZ = s.size();
            for (int j=0;j<SZ;j++) {
                if (s[j] == ' ') {
                    if (m[cur] == 0) {
                        cnt++;
                        m[cur] = cnt;
                    }
                    a[i].pb(m[cur]);
                    cur = "";
                } else {
                    cur += s[j];
                }
            }
        }
        for (int i=1;i<=n;i++) {
            set<vector<int>> s;
            for (int j=0;j<a[i].size();j++) {
                vector<int> v;
                for (int k=j;k<a[i].size();k++) {
                    v.pb(a[i][k]);
                    
                    if (s.find(v) == s.end()) ans[v]++;
                    s.insert(v);
                }
            }
        }
        // for (int i=1;i<=n;i++) {
        //     for (auto x : a[i]) cout << x << " ";
        //     cout << endl;
        // }
 
        while (q--) {
            vector<int> v;
            string s;
            getline(cin, s);
            s += ' ';
            string cur = "";
            int SZ = s.size();
            for (int j=0;j<SZ;j++) {
                if (s[j] == ' ') {
                    if (m[cur] == 0) {
                        cnt++;
                        m[cur] = cnt;
                    }
                    v.pb(m[cur]);
                    cur = "";
                } else {
                    cur += s[j];
                }
            }
 
            // int M = v.size();
            // lps[0] = 0;
            // int len = 0;
            // int i = 1;
            // while (i < M) {
            //     if (v[i] == v[len]) {
            //         len++;
            //         lps[i] = len;
            //         i++;
            //     } else {
            //         if (len != 0) len = lps[len-1];
            //         else {
            //             lps[i] = 0;
            //             i++;
            //         }
            //     }
            // }
 
            // int ans = 0;
            // for (int i=1;i<=n;i++) {
            //     bool found = 0;
            //     int g = 0;
            //     int h = 0;
            //     int N = a[i].size();
            //     if (M > N) continue;
            //     while (g < N) {
            //         if (v[h] == a[i][g]) {
            //             g++;
            //             h++;
            //         }
            //         if (h == M) {
            //             found = 1;
            //             break;
            //         } else if (g < N && v[h] != a[i][g]) {
            //             if (h != 0) h = lps[h-1];
            //             else g++;
            //         }
            //     }
            //     if (found) ans++;
            // }
            cout << ans[v] << "\n";
            // for (auto x : v) cout << x << " ";
            // cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
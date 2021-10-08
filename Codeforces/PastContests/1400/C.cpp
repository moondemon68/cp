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
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        string ans = "";
        for (int i=0;i<s.size();i++) ans += '2';
        for (int i=0;i<x;i++) {
            vector<int> v;
            for (int j=i;j<s.size();j+=x) {
                v.pb(j);
            }
            string t = "";
            for (int j=0;j<v.size();j++) {
                t += s[v[j]];
            }
            
            // 1 smua
            bool y = 1;
            for (int j=0;j<t.size();j++) {
                if (t[j] == '0') {
                    y = 0;
                    break;
                }
            }
            if (y) {
                for (int j=0;j<t.size();j++) ans[v[j]] = '1';
                continue;
            }

            // 0 smua
            y = 1;
            for (int j=0;j<t.size();j++) {
                if (t[j] == '1') {
                    y = 0;
                    break;
                }
            }
            if (y) {
                for (int j=0;j<t.size();j++) ans[v[j]] = '0';
                continue;
            }

            // alternating
            for (int j=0;j<t.size();j++) {
                if (t[j] == '0') {
                    if (j < t.size()-1) ans[v[j+1]] = '0';
                    if (j > 0) ans[v[j-1]] = '0';
                }
            }
            for (int j=0;j<t.size();j++) {
                if (ans[v[j]] == '2') ans[v[j]] = '1';
            }
            continue;

            ans = "-1";
            break;
        }
        bool y = 1;
        for (int i=0;i<s.size();i++) {
            if ((i-x) >= 0 && s[i] == '1' && ans[i-x] == '1') continue;
            if ((i+x) < s.size() && s[i] == '1' && ans[i+x] == '1') continue;
            if (s[i] == '0') continue;
            y = 0;
        }
        if (!y) ans = "-1";
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
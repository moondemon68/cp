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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i=0;i<s.size()-6;i++) {
            if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'a' && s[i+3] == 'c' && s[i+4] == 'a' && s[i+5] == 'b' && s[i+6] == 'a') cnt++;
        }
        if (cnt > 1) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> v;
        for (int i=0;i<s.size()-6;i++) {
            if ((s[i] == 'a' || s[i] == '?') && (s[i+1] == 'b' || s[i+1] == '?') && (s[i+2] == 'a' || s[i+2] == '?') && (s[i+3] == 'c' || s[i+3] == '?') && (s[i+4] == 'a' || s[i+4] == '?') && (s[i+5] == 'b' || s[i+5] == '?') && (s[i+6] == 'a' || s[i+6] == '?')) {
                v.pb(i);
            }
        }
        bool y = 0;
        for (auto x : v) {
            string t = s;
            t[x] = 'a';
            t[x+1] = 'b';
            t[x+2] = 'a';
            t[x+3] = 'c';
            t[x+4] = 'a';
            t[x+5] = 'b';
            t[x+6] = 'a';
            for (int i=0;i<t.size();i++) {
                if (t[i] == '?') t[i] = 'z';
            }
            int cnt2 = 0;
            for (int i=0;i<t.size()-6;i++) {
                if (t[i] == 'a' && t[i+1] == 'b' && t[i+2] == 'a' && t[i+3] == 'c' && t[i+4] == 'a' && t[i+5] == 'b' && t[i+6] == 'a') cnt2++;
            }
            if (cnt2 == 1) {
                y = 1;
                cout << "YES" << endl;
                cout << t << endl;
                break;
            }
        }
        if (!y) {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

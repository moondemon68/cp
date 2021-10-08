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
        for (int i=1;i<s.size();i++) {
            if (i >= 2 && s[i] == s[i-2] && s[i-2] != '?') {
                s[i] = '?';
            }
            if (s[i] == s[i-1] && s[i-1] != '?') {
                s[i] = '?';
            }
        }
        int ans = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '?') ans++;
        }
        // cout << s << endl;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

// 40
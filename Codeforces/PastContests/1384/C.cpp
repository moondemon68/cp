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
        string s,t;
        cin >> s >> t;
        bool y = 1;
        for (int i=0;i<s.size();i++) {
            if (t[i] < s[i]) y = 0;
        }
        if (!y) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for (int i=1;i<=200;i++) {
            char c = 'z';
            for (int j=0;j<n;j++) {
                if (s[j] == t[j]) continue;
                if (s[j] < c && s[j] != t[j]) c = s[j];
            }
            bool a[n+5];
            memset (a,0,sizeof(a));
            for (int j=0;j<n;j++) {
                if (s[j] == t[j]) continue;
                if (s[j] == c) a[j] = 1;
            }
            char target = 'z';
            for (int j=0;j<n;j++) {
                if (s[j] == t[j]) continue;
                if (a[j] && t[j] < target) target = t[j];
            }
            for (int j=0;j<n;j++) {
                if (s[j] == t[j]) continue;
                if (target <= t[j] && a[j]) {
                    s[j] = target;
                }
            }
            if (c == 'z') break;
            ans = i;
            // cout << s << endl;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
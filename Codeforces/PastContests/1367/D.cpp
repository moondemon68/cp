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
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int c[35];
        memset (c,0,sizeof(c));
        for (int i=0;i<s.size();i++) {
            c[s[i]-'a']++;
        }
        string ans = "";
        ans += '.';
        for (int i=1;i<=n;i++) ans += '.';
        int x = 25;
        while (true) {
            vector<int> v;
            for (int i=1;i<=n;i++) {
                if (a[i] == 0) v.pb(i);
            }
            for (int i=x;i>=0;i--) {
                if (c[i] >= v.size()) {
                    for (auto p : v) {
                        ans[p] = 'a'+i;
                        a[p] = -1;
                    }
                    for (int j=1;j<=n;j++) {
                        for (auto p : v) {
                            a[j] -= abs(j-p);
                        }
                    }
                    x = i-1;
                    break;
                }
            }
            bool y = 1;
            for (int i=1;i<ans.size();i++) {
                if (ans[i] == '.') y = 0;
            }
            if (y) break;
        }
        for (int i=1;i<ans.size();i++) cout << ans[i];
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
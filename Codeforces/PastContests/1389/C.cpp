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
        int cnt[10];
        memset (cnt,0,sizeof(cnt));
        for (int i=0;i<s.size();i++) {
            cnt[s[i]-'0']++;
        }
        int ans = 0;
        for (int i=0;i<=9;i++) {
            ans = max(ans, cnt[i]);
        }
        for (int i=0;i<=9;i++) {
            for (int j=0;j<=9;j++) {
                bool y = 0;
                int x = 0;
                for (int k=0;k<s.size();k++) {
                    if (!y && (s[k]-'0') == i) {
                        y = 1;
                        x++;
                    } else if (y && (s[k]-'0') == j) {
                        y = 0;
                        x++;
                    } 
                }
                if (x%2 == 0) ans = max(ans, x);
            }
        }
        cout << s.size() - ans << endl;

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
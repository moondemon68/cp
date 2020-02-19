#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL dp[100005][30];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    LL ans = 0;
    LL cnt[30];
    memset (cnt,0,sizeof(cnt));
    for (LL i=0;i<s.size();i++) {
        cnt[s[i]-'a']++;
        ans = max(ans, cnt[s[i]-'a']);
    }
    memset (dp,0,sizeof(dp));
    for (LL i=0;i<s.size();i++) {
        dp[i][s[i]-'a'] = 1;
    }
    for (LL i=1;i<s.size();i++) {
        for (LL j=0;j<26;j++) {
            dp[i][j] += dp[i-1][j];
        }
    }
    LL p[30][30];
    memset (p,0,sizeof(p));
    for (LL i=0;i<s.size();i++) {
        for (LL k=0;k<26;k++) {
            p[s[i]-'a'][k] += (dp[s.size()-1][k] - dp[i][k]);
        }
    }
    for (LL i=0;i<26;i++) {
        for (LL j=0;j<26;j++) {
            ans = max(ans, p[i][j]);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
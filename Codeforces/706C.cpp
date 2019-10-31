#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

bool gre(string a,string b) {
    for (LL i=0;i<min(a.size(),b.size());i++) {
        if (a[i]==b[i]) continue; else return a[i]>b[i];
    }
    return a.size()>=b.size();
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL c[n+5];
    for (LL i=1;i<=n;i++) cin >> c[i];
    string s[n+5];
    for (LL i=1;i<=n;i++) cin >> s[i];
    string r[n+5];
    for (LL i=1;i<=n;i++) {
        r[i]=s[i];
        reverse(r[i].begin(),r[i].end());
    }
    LL dp[n+5][2];
    for (LL i=1;i<=n;i++) {
        dp[i][0]=dp[i][1]=1234567890987654321;
    }
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=c[1];
    for (LL i=2;i<=n;i++) {
        if (gre(s[i],s[i-1])) {
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        }
        if (gre(s[i],r[i-1])) {
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }
        if (gre(r[i],s[i-1])) {
            dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
        }
        if (gre(r[i],r[i-1])) {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
        }
    }
    //for (LL i=1;i<=n;i++) cout << dp[i][0] << dp[i][1] << endl;
    if (min(dp[n][0],dp[n][1])==1234567890987654321) cout << -1 << endl; 
    else cout << min(dp[n][0],dp[n][1]) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
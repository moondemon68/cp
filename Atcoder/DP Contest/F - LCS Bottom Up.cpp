#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int dp[3005][3005];
string s,t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;
    memset (dp,0,sizeof(dp));
    for (int i=0;i<=s.size();i++) {
        for (int j=0;j<=t.size();j++) {
            if (i==0||j==0) dp[i][j]=0;
            else if (s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    /*
    for (int i=0;i<=s.size();i++) {
        for (int j=0;j<=t.size();j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    int len=dp[s.size()][t.size()];
    string lcs="";
    int a=s.size(),b=t.size();
    while (lcs.size()!=len) {
        if (s[a-1]==t[b-1]) {
            lcs+=s[a-1];
            a--;
            b--;
        } else if (dp[a-1][b]>dp[a][b-1]) {
            a--;
        } else b--;
        //cout << lcs << endl;
    }
    reverse(lcs.begin(),lcs.end());
    cout << lcs << endl;
    return 0;
}

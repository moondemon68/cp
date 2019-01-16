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
    int solve(int a,int b) {
        if (a==0||b==0) return dp[a][b]=0;
        if (dp[a][b]!=-1) return dp[a][b];
        if (s[a-1]==t[b-1]) return dp[a][b]=solve(a-1,b-1)+1;
        else return dp[a][b]=max(solve(a-1,b),solve(a,b-1));
    }
     
    int main () {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> s >> t;
        memset (dp,-1,sizeof(dp));
        int len=solve(s.size(),t.size());
        /*for (int i=0;i<=s.size();i++) {
            for (int j=0;j<=t.size();j++) {
                cout << dp[i][j] << " ";
                if (dp[i][j]!=-1) cout << " ";
            }
            cout << endl;
        }*/
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
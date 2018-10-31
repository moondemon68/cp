#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n,m,dp[5005][5005];
string a,b;

int LCS(int p,int q) {
  if (p<=0||q<=0) return 0;
  if (dp[p][q]!=-1) return dp[p][q];
  if (a[p-1]==b[q-1]) return dp[p][q]=LCS(p-1,q-1)+1;
  else return dp[p][q]=max(LCS(p-1,q),LCS(p,q-1));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    m=n;
    cin >> a;
    b=a;
    reverse(b.begin(),b.end());
    memset (dp,-1,sizeof(dp));
    int ans=LCS(n,m);
    /*
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (dp[i][j]>=0) cout << " ";
        cout << dp[i][j];
      }
      cout << endl;
    }
    */
    string answer="";
    while (n>0&&m>0) {
      if (a[n-1]==b[m-1]) {
        answer+=a[n-1];
        n--;
        m--;
      } else if (dp[n-1][m]<dp[n][m-1]) m--;
      else n--;
    }
    //reverse(answer.begin(),answer.end());
    cout << answer << endl;
    return 0;
}
/*
4
jcpc
6
itachi
*/

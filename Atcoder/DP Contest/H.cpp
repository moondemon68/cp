#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL dp[1005][1005];
char a[1005][1005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    cin >> r >> c;
    for (int i=1;i<=r;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j]=s[j-1];
        }
    }    
    memset (dp,0,sizeof(dp));
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (i==1&&j==1) {
                dp[i][j]=1;
                continue;
            }
            if (a[i][j-1]=='.') dp[i][j]+=dp[i][j-1];
            if (a[i-1][j]=='.') dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }
    /*
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[r][c];
    return 0;
}

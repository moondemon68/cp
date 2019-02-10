#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[5205][5205];
int dp[5205][5205];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    memset (a,0,sizeof(a));
    for (int i=0;i<n;i++) {
        string s;
        cin >> s;
        for (int j=0;j<s.size();j++) {
            if (s[j]=='0') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=0;
                a[i][j*4+2]=0;
                a[i][j*4+3]=0;
            } else if (s[j]=='1') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=0;
                a[i][j*4+2]=0;
                a[i][j*4+3]=1;
            } else if (s[j]=='2') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=0;
                a[i][j*4+2]=1;
                a[i][j*4+3]=0;
            } else if (s[j]=='3') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=0;
                a[i][j*4+2]=1;
                a[i][j*4+3]=1;
            } else if (s[j]=='4') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=1;
                a[i][j*4+2]=0;
                a[i][j*4+3]=0;
            } else if (s[j]=='5') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=1;
                a[i][j*4+2]=0;
                a[i][j*4+3]=1;
            } else if (s[j]=='6') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=1;
                a[i][j*4+2]=1;
                a[i][j*4+3]=0;
            } else if (s[j]=='7') {
                a[i][j*4+0]=0;
                a[i][j*4+1]=1;
                a[i][j*4+2]=1;
                a[i][j*4+3]=1;
            } else if (s[j]=='8') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=0;
                a[i][j*4+2]=0;
                a[i][j*4+3]=0;
            } else if (s[j]=='9') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=0;
                a[i][j*4+2]=0;
                a[i][j*4+3]=1;
            } else if (s[j]=='A') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=0;
                a[i][j*4+2]=1;
                a[i][j*4+3]=0;
            } else if (s[j]=='B') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=0;
                a[i][j*4+2]=1;
                a[i][j*4+3]=1;
            } else if (s[j]=='C') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=1;
                a[i][j*4+2]=0;
                a[i][j*4+3]=0;
            } else if (s[j]=='D') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=1;
                a[i][j*4+2]=0;
                a[i][j*4+3]=1;
            } else if (s[j]=='E') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=1;
                a[i][j*4+2]=1;
                a[i][j*4+3]=0;
            } else if (s[j]=='F') {
                a[i][j*4+0]=1;
                a[i][j*4+1]=1;
                a[i][j*4+2]=1;
                a[i][j*4+3]=1;
            }
        }
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i==1&&j==1) dp[i][j]=a[i-1][j-1];
            else if (i==1) dp[i][j]=a[i-1][j-1]+dp[i][j-1];
            else if (j==1) dp[i][j]=a[i-1][j-1]+dp[i-1][j];
            else dp[i][j]=a[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    /*
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int x=n;x>=2;x--) {
        if (n%x!=0) continue;
        bool y=1;
        for (int i=0;i<=n-x;i+=x) {
            for (int j=0;j<=n-x;j+=x) {
                if (dp[i+x][j+x]-dp[i][j+x]-dp[i+x][j]+dp[i][j]!=x*x&&dp[i+x][j+x]-dp[i][j+x]-dp[i+x][j]+dp[i][j]!=0) {
                    y=0;
                    //cout << x << " " << dp2[i+x][j+x]-dp2[i][j+x]-dp2[i+x][j]+dp2[i][j] << endl;
                }
            }
            if (!y) break;
        }
        if (y) {
            cout << x << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
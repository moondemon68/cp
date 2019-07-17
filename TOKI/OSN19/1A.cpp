#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    cin >> r >> c;
    int a[r+5][c+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=r;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=c;j++) {
            if (s[j-1]=='1') a[i][j]=1; else a[i][j]=0;
        }
    }   
    int num=0;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (a[i][j]==1) num++;
        }
    }
    int dp[r+5][c+5];
    memset (dp,0,sizeof(dp));
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            dp[i][j]=a[i][j];
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
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
    vector<int> fac;
    for (int i=1;i*i<=num;i++) {
        if (num%i==0) {
            fac.pb(i);
            fac.pb(num/i);
        }
    }
    sort (fac.begin(),fac.end());
    int ans=123456789;
    for (int i=0;i<fac.size();i++) {
        int p=fac[i],q=num/fac[i];
        //cout << p << " " << q << endl;
        for (int j=1;j<=r;j++) {
            for (int k=1;k<=c;k++) {
                pii u=mp(j,k),v=mp(j+p-1,k+q-1);
                if (j+p-1>r||k+q-1>c) break;
                //cout << u.fi << " " << u.se << " " << v.fi << " " << v.se << endl;
                int x=dp[v.fi][v.se]+dp[u.fi-1][u.se-1]-dp[u.fi-1][v.se]-dp[v.fi][u.se-1];
                ans=min(ans,num-x);
            }
        }
    }
    if (ans==123456789) ans=-1;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
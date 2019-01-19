#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

double dp[3005][3005];
double solve(int pos,int rem) {
    //cout << pos << rem << endl;
    if (pos==0&&rem==0) return 0;
    if (pos>0&&rem==0) return -123456;
    if (pos==0&&rem>0) return -123456;
    if (dp[pos][rem]!=-1) return dp[pos][rem];
    double best=0;
    for (double i=1;i<=rem;i+=1) {
        //cout << i << rem;
        best=max(best,solve(pos-1,rem-i)+i/rem);
    }
    return dp[pos][rem]=best;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n;
    for (k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                dp[i][j]=-1;
            }
        }
        cout << fixed << setprecision(10) << solve(k,n) << endl;
    }
    /*
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=n;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}

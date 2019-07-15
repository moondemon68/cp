#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 12345678900000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n,m;
ll dp[105][100100];
int val[105],wg[105];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i=1;i<=n;i++){
        cin >> val[i];
    }

    for (int i=1;i<=n;i++){
        cin >> wg[i];
    }

    // dp INITIALITATION
    for (int i=0;i<=n;i++){
        for (int j=0;j<=100001;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;

    for (int i=1;i<=n;i++){
        for (int j=0;j<=100000;j++) dp[i][j]=dp[i-1][j];
        for (int j=val[i];j<=100000;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j-val[i]]+(ll)wg[i]);
        }
    }

    for (int i=100000;i>=0;i--){
        if (dp[n][i]<=m){
            cout << i << '\n';
            break;
        }
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
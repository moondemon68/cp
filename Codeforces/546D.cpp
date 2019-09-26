#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int dp[5000005],dpp[5000005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset (dp,0,sizeof(dp));
    dp[1]=1;
    for (int i=2;i<=5000000;i++) {
        if (dp[i]==0) dp[i]=i;
        for (int j=i;j<=5000000;j+=i) {
            if (dp[j]==0) dp[j]=i;
        }
    }
    for (int i=1;i<=5000000;i++) {
        dpp[i]=0;
        int x=i;
        while (x>1) {
            dpp[i]++;
            x/=dp[x];
        }
        dpp[i]+=dpp[i-1];
    }
    //for (int i=1;i<=10;i++) cout << dpp[i] << " ";
    int tc;
    cin >> tc;
    while (tc--) {
        int x,y;
        cin >> x >> y;
        cout << dpp[x]-dpp[y] << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
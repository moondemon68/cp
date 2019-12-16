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
LL dp[1000005]; 
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c[25];
    c[0]=1;
    for (LL i=1;i<=22;i++) c[i]=c[i-1] * 2;
    int b[25];
    for (LL i=1;i<=22;i++) b[i-1]=c[i]-1;
    // for (int i=0;i<20;i++) cout << b[i] << " ";
    // cout << endl;
    memset(dp, 0, sizeof(dp)); 
    dp[0] = 1;  
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 0; j < 22; j++) {
            if (i >= b[j]) {
                dp[i] += dp[i - b[j]]; 
                dp[i]%=MOD;
            }
        }
    }
    dp[0]=1;
    for (int i=1;i<=1000000;i++) {
        dp[i]*=2;
        dp[i]%=MOD;
    }
    for (int i=1;i<=1000000;i++) {
        dp[i]+=dp[i-1];
        dp[i]%=MOD;
    }
    LL q;
    cin >> q;
    while (q--) {
        LL g,h;
        cin >> g >> h;
        cout << ((dp[h]-dp[g-1])+MOD)%MOD << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
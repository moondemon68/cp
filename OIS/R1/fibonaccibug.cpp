#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL f[25];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    f[0]=1;
    f[1]=1;
    for (LL i=2;i<=24;i++) f[i]=f[i-1]+f[i-2];

    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,k;
        cin >> n >> k;
        vector<LL> W,V;
        for (int i=1;i<=n;i++) {
            LL a,b;
            cin >> a >> b;
            if (a <= 24) {
                W.pb(f[a]);
                V.pb(b);
            }
        }
        LL dp[k+1];
        memset (dp,0,sizeof(dp));
        for (int i=0;i<=k;i++) {
            for (int j=0;j<W.size();j++) {
                if (W[j]<=i) dp[i] = max(dp[i], dp[i-W[j]]+V[j]);
            }
        }
        cout << dp[k] << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
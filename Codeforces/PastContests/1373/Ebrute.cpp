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

int dp[89999999];

LL f(int p) {
    if (p < 90000000 && dp[p] != 0) return dp[p];
    LL res = 0;
    while (p) {
        res += p%10;
        p /= 10;
    }
    return dp[p] = res;
    // return res;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL ans[155];
    memset (ans,-1,sizeof(ans));
    for (LL x=0;x<=1000000;x++) {
        if (x % 1000000 == 0) cout << x << endl;
        int i = f(x) + f(x+1) + f(x+2) + f(x+3) + f(x+4) + f(x+5) + f(x+6) + f(x+7) + f(x+8) + f(x+9);
        if (i <= 150) {
            if (ans[i] == -1) ans[i] = x;
            // cout << i << endl;
        }
    }
    cout << '{';
    for (LL i=1;i<=150;i++) {
        cout << ans[i];
        if (i != 150) cout << ',';
    }
    cout << '}';
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
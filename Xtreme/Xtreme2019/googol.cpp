#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;
LL mod=1;
LL fastpow(LL x, LL p) {
    LL res = 1;
    while (p > 0) { 
        if (p & 1) {
            res = ((res%mod) * (x%mod))%mod; 
            res %= mod;
        }
        p = p >> 1;
        x = ((x%mod) * (x%mod))%mod;
        x %= mod;
    } 
    return res%mod;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        LL x,y;
        cin >> x >> y;
        mod = 1;
        for (int i=1;i<=y;i++) mod *= 10;
        LL pow5[20];
        pow5[0]=1;
        for (int i=1;i<=10;i++) pow5[i]=pow5[i-1]*5;
        LL pow2[20];
        pow2[0]=1;
        for (int i=1;i<=10;i++) pow2[i]=pow2[i-1]*2;
        LL a=0,b=0;
        LL xx=x;
        while (xx%2==0) {
            a++;
            xx/=2;
        }
        while (xx%5==0) {
            b++;
            xx/=5;
        }
        LL ans = fastpow(2,a*4*pow5[y-1]);
        ans%=mod;
        ans *= fastpow(5,b*pow2[y-1]);
        ans%=mod;
        // cout << ans << endl;
        LL jawaban=ans;
        for (int i=1;i<=86399;i++) {
            ans *= x;
            ans %= mod;
            if (ans<jawaban) {
                jawaban = ans;
            }
        }
        cout << jawaban << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
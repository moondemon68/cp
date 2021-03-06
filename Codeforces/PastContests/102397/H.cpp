#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL power(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b&1) res = (res * a)%MOD;
        b >>= 1;
        a = (a*a)%MOD;
    }
    return res%MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL cnt[100005];
    memset (cnt,0,sizeof(cnt));
    for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        cnt[x]++;
    }
    LL ans=0;
    for (LL i=1;i<=100000;i++) {
        ans+=power(2,cnt[i])-1;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
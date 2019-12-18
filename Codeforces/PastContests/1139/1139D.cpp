#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL fastPow(LL a,LL x,LL m) {
    LL ret=1;
    while (x>0) {
        if (x&1) {
            ret*=a;
            ret%=m;
        }
        x=x>>1;
        a*=a;
        a%=m;
    }
    return ret;
}

LL gcd(LL a,LL b,LL &x,LL &y) {
    if (a==0) {
        x=0;
        y=1;
        return b;
    }
    LL x1,y1;
    LL d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

LL inverseModulo(LL a,LL m) {
    LL x,y;
    LL ans=gcd(a,m,x,y);
    return (x%m+m)%m;
}
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL ans=0;
    LL n;
    cin >> n;
    if (n==1) cout << 1;
    else if (n==2) cout << 2;
    else cout << (2*n-1)*(inverseModulo(3,MOD))%MOD;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
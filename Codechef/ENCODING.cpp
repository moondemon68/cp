#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL p[20];

LL f(LL x) {
    vector<LL> v;
    while (x>0) {
        v.pb(x%10);
        x/=10;
    }
    LL ret=0;
    v.pb(-1);
    for (LL i=0;i<v.size()-1;i++) {
        if (v[i]==v[i+1]) continue;
        else {
            ret+=p[i]*v[i];
            ret%=MOD;
        }
    }   
    return ret%MOD;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    memset (p,0,sizeof(p));
    p[0]=1;
    for (int i=1;i<=20;i++) {
        p[i]=p[i-1]*10;
        p[i]%=MOD;
    }
    while (tc--) {
        LL nl,nr,l,r;
        cin >> nl >> l >> nr >> r;
        LL ans=0;
        for (LL i=l;i<=r;i++) {
            ans+=f(i);
            ans%=MOD;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
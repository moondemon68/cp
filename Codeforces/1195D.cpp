#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

LL power[19];

LL selipin(LL x,LL m) {
    LL xx=x;
    LL ret=0;
    vector<LL> p;
    while (x>0) {
        p.pb(x%10);
        x/=10;
    }
    reverse(p.begin(),p.end());
    ret=xx/power[min((int)m,(int)p.size())]*power[min((int)m,(int)p.size())*2];
    for (LL i=max(0,(int)p.size()-(int)m);i<p.size();i++) {
        ret+=p[i]*power[(p.size()-i)*2-1];
    }
    return ret;
}

int itung(LL x) {
    vector<LL> p;
    while (x>0) {
        p.pb(x%10);
        x/=10;
    }
    return p.size();
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    power[0]=1;
    for (int i=1;i<=18;i++) {
        power[i]=power[i-1]*10;
    }
    LL n;
    cin >> n;
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    LL cnt[11];
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        cnt[itung(a[i])]++;
    }
    LL ans=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=10;j++) {
            ans+=cnt[j]*selipin(a[i],j);
            ans+=cnt[j]*selipin(a[i],j)/10;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
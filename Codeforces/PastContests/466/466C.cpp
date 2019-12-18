#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    LL tot=0;
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
        tot+=a[i];
    }
    if (tot%3!=0) {
        cout << 0 << endl;
        return 0;
    }
    LL x=tot/3;
    LL ans=0,cur=0;
    LL c[n+5];
    memset (c,0,sizeof(c));
    for (LL i=n;i>=1;i--) {
        cur+=a[i];
        if (cur==x) c[i]=1;
    }
    for (LL i=n-1;i>=1;i--) {
        c[i]+=c[i+1];
    }
    cur=0;
    for (LL i=1;i<=n-2;i++) {
        cur+=a[i];
        if (cur==x) {
            ans+=c[i+2];
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
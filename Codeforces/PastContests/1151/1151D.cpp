#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pair<LL,LL> a,pair<LL,LL> b) {
    if (a.fi==b.fi) return a.se<b.se;
    return a.fi>b.fi;
}
bool cmp1(pair<LL,LL> a,pair<LL,LL> b) {
    if (a.se==b.se) return a.fi>b.fi;
    return a.se<b.se;
}
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pair<LL,LL> a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort (a+1,a+n+1,cmp);
    LL ans=0,ans1=0;
    for (LL i=1;i<=n;i++) {
        ans+=a[i].fi*(i-1)+a[i].se*(n-i);
    }
    sort (a+1,a+n+1,cmp1);
    for (LL i=1;i<=n;i++) {
        ans1+=a[i].fi*(i-1)+a[i].se*(n-i);
    }
    cout << min(ans1,ans) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
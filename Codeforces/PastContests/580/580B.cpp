#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,x;
    cin >> n >> x;
    pair<LL,LL> a[100005];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort (a+1,a+n+1);
    for (LL i=1;i<=n;i++) a[i].se+=a[i-1].se;
    LL l=1,r=1,ans=a[1].se;
    while (l<=n&&r<=n) {
        if (a[r+1].fi-a[l].fi<x||l>r) r++; else l++;
        ans=max(a[r].se-a[l-1].se,ans);
    }
    cout << ans << endl;
    return 0;
}

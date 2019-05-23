#include <bits/stdc++.h>
#include <deque>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5],b[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=1;i<=n;i++) cin >> b[i];
    sort (b+1,b+n+1);
    reverse(b+1,b+n+1);
    for (LL i=1;i<=n;i++) {
        a[i]*=(i)*(n-i+1);
        //cout << i*(n-i+1) << " ";
    }
    sort (a+1,a+n+1);
    LL ans=0;
    for (LL i=1;i<=n;i++) {
        ans+=((a[i]%MOD)*(b[i]%MOD))%MOD;
        ans%=MOD;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
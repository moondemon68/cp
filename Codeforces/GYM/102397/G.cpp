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
    LL n,k;
    cin >> n >> k;
    LL a[n+5],b[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=1;i<=n;i++) cin >> b[i];
    LL ca[100005],cb[100005];
    memset (ca,0,sizeof(ca));
    memset (cb,0,sizeof(cb));
    for (LL i=1;i<=n;i++) ca[a[i]]++;
    for (LL i=1;i<=n;i++) cb[b[i]]++;
    LL ansa=0,ansb=0;
    for (LL i=1;i<=k;i++) {
        if (k-i != i) ansa+=ca[k-i] * ca[i];
        else ansa+=ca[i]*(ca[i]-1);
    }
    for (LL i=1;i<=k;i++) {
        if (k-i != i) ansb+=cb[k-i] * cb[i];
        else ansb+=cb[i]*(cb[i]-1);
    }
    // cout << ansa << " " << ansb << endl;
    if (ansa>ansb) cout << "Mahmoud";
    else if (ansa==ansb) cout << "Draw";
    else cout << "Bashar";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
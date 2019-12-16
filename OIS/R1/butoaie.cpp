#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int a[200005], n;
bool done() {
    for (int i=1;i<=n;i++) if (a[i]>0) return 0;
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> n >> k;
    int p,q;
    cin >> p >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (q > p) {
        swap(p,q);
        k = n-k;
    }
    int dmg[n+5];
    for (int i=1;i<=n;i++) {
        if (i<=n-k) dmg[i]=q;
        else dmg[i]=p;
    }
    sort (dmg+1,dmg+n+1);
    reverse(dmg+1,dmg+n+1);
    sort (a+1,a+n+1);
    reverse(a+1,a+n+1);
    int x;
    int ans=0;
    for (int i=1;i<=123456789;i++) {
        if (a[1] <= p && a[1] > 0) {
            if (1<=k) {
                x = (a[1])/p;
            } else {
                x = (a[1])/q;
            }
            x++;
            ans+=x;
            for (int j=1;j<=n;j++) {
                a[j]-=dmg[j]*x;
            }
            sort (a+1,a+n+1);
            reverse(a+1,a+n+1);
        }
        else if (a[1]>0) {
            if (1<=k) {
                x = (a[1])/p;
            } else {
                x = (a[1])/q;
            }
            ans+=x;
            for (int j=1;j<=n;j++) {
                a[j]-=dmg[j]*x;
            }
            sort (a+1,a+n+1);
            reverse(a+1,a+n+1);
        } else break;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
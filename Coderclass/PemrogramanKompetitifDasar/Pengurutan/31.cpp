//Menyusun Komik
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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    pii p[n+5];
    for (int i=1;i<=n;i++) p[i]=mp(a[i],i);
    sort (p+1,p+n+1);
    int ans=0;
    for (int i=1;i<=n;i++) {
        if (p[i].se==i) continue;
        swap(p[i].fi,p[p[i].se].fi);
        swap(p[i].se,p[p[i].se].se);
        if (p[i].se!=i) i--;
        ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
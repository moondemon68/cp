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
    LL a[n+5],v[n+5],u[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    v[0]=0; u[0]=0;
    for (int i=1;i<=n;i++) v[i]=v[i-1]+a[i];
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++) u[i]=u[i-1]+a[i];
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        if (x==1) cout << v[z]-v[y-1] << endl; else cout << u[z]-u[y-1] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
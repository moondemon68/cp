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
    int n,m;
    cin >> n >> m;
    LL x[n+5],p[m+5];
    for (int i=1;i<=n;i++) cin >> x[i];
    for (int i=1;i<=m;i++) cin >> p[i];
    LL g=x[2]-x[1];
    for (int i=1;i<n;i++) {
        g=__gcd(g,x[i+1]-x[i]);
    }
    for (int i=1;i<=m;i++) {
        if (g%p[i]==0) {
            cout << "YES" << endl;
            cout << x[1] << " " << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
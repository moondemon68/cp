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
    LL l=12345678987654321,r=0;
    for (LL i=1;i<=n;i++) {
        LL p,q;
        cin >> p >> q;
        l=min(l,p);
        r=max(r,q);
    }
    cout << r*(r+1)/2-(l)*(l-1)/2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
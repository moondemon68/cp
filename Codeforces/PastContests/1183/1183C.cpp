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
    LL q;
    cin >> q;
    while (q--) {
        LL k,n,a,b;
        cin >> k >> n >> a >> b;
        LL l=0,h=n,ans=-1;
        while (l<=h) {
            LL m=(l+h)/2;
            //cout << m << endl;
            LL p=m,v=n-m;
            LL g=p*a+v*b;
            if (g>=k) {
                h=m-1;
            } else {
                ans=m;
                l=m+1;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
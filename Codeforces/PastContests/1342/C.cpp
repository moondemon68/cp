#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL a,b,q;
        cin >> a >> b >> q;
        while (q--) {
            LL l,r;
            cin >> l >> r;
            l--;
            if (__gcd(a,b) == min(a,b)) cout << 0 << " ";
            else {
                LL lcm = a/__gcd(a,b)*b;

                LL ansl = (l/lcm) * max(a,b);
                if (l%lcm < max(a,b)) ansl += (l%lcm)+1;
                else ansl += max(a,b);

                LL ansr = (r/lcm) * max(a,b);
                if (r%lcm < max(a,b)) ansr += (r%lcm)+1;
                else ansr += max(a,b);
                
                cout << (r-l+1)-(ansr-ansl)-1 << " ";
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
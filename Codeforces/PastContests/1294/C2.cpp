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
    int tc;
    cin >> tc;
    while (tc--) {
        LL n;
        cin >> n;
        LL a=-1,b=-1,c=-1, x= n;
        for (LL i=2;i*i<=n;i++) {
            if (n%i == 0) {
                a = i;
                n/=i;
                break;
            }
        }
        for (LL i = 2;i*i<=n;i++) {
            if (i == a || (n%i == 0 &&  n/i == a)) continue;
            if (n % i == 0) {
                if (i == n/i) continue;
                b = i;
                n/=i;
                break;
            }
        }
        c = n;
        if (a == -1 || b == -1 || c == -1 || a*b*c != x) cout << "NO" << endl; else cout << "YES" << endl << a << ' ' << b << " " << c << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
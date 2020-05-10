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
        int n,a,b,c,d;
        cin >> n >> a >> b >> c >> d;
        bool y = 0;
        int x = n*(a+b);
        for (int i=1;i<=n;i++) {
            if (x <= (c+d) && x >= (c-d)) y = 1;
            if (x > (c+d)) {
                x -= b*2;
                if (x <= (c+d)) {
                    y = 1;
                    break;
                }
            }
        }
        if (y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
        LL n,d;
        cin >> n >> d;
        if (d<=n) {
            cout << "YES" << endl;
            continue;
        }
        bool y = 0;
        for (LL i=1;i*i<=d;i++) {
            if (i+(d+i)/(i+1) <= n) {
                y = 1;
                continue;
            }
        }
        

        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
        int n,x;
        cin >> n >> x;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        bool y = 0;
        for (int i=1;i<=n;i++) {
            if (a[i] == x) {
                cout << 1 << endl;
                y = 1;
                break;
            }
        }
        if (!y) cout << max(2, (x+a[n]-1)/a[n]) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
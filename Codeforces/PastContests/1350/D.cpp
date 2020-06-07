#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
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
        int n,k;
        cin >> n >> k;
        int a[n+5];
        memset (a,0,sizeof(a));
        for (int i=1;i<=n;i++) cin >> a[i];
        bool y = 0;
        for (int i=1;i<=n;i++) {
            if (a[i] == k) y = 1;
        }
        bool yy = 0;
        if (n == 1) yy = 1;
        for (int i=1;i<=n;i++) {
            if (a[i] >= k) {
                if (a[i+1] >= k || a[i+2] >= k) yy = 1;
            }
        }
        if (y && yy) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
        int n;
        cin >> n;
        int a[2*n+5];
        for (int i=1;i<=2*n;i++) cin >> a[i];
        bool d[n+5];
        memset (d,0,sizeof(d));
        for (int i=1;i<=2*n;i++) {
            if (!d[a[i]]) {
                cout << a[i] << " ";
                d[a[i]] = 1;
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
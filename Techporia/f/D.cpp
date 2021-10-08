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
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int b[2*n+5];
        memset (b,-1,sizeof(b));
        set<int> s;
        for (int i=1;i<=n;i++) {
            b[2*i-1] = a[i];
            s.insert(a[i]);
        }
        for (int i=2;i<=2*n;i+=2) {
            for (int j=b[i-1]+1;j<=2*n;j++) {
                if (s.find(j) == s.end()) {
                    s.insert(j);
                    b[i] = j;
                    break;
                }
            }
        }
        bool y = 1;
        for (int i=1;i<=2*n;i++) {
            if (b[i] == -1) y = 0;
        }
        if (y) {
            for (int i=1;i<=2*n;i++) cout << b[i] << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    if (k == 1) {
        for (int k=1;k<=n;k+=10) {
            cout << "? " << min(10, n-k+1) << endl;
            int ans = -1;
            for (int i=k;i<=min(k+9, n);i++) {
                cout << n-1 << " ";
                for (int j=1;j<=n;j++) {
                    if (j == i) continue;
                    cout << j << " ";
                }
                cout << endl;
            }
            for (int i=k;i<=min(k+9, n);i++) {
                string s;
                cin >> s;
                if (s == "TIDAK") ans = i;
            }
            if (ans == -1) continue;
            cout << "! " << ans << endl;
            return 0;
        }
    } else {
        
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
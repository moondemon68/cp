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
        int n,a,b;
        cin >> n >> a >> b;
        int win=0;
        for (int i=1;i<=a;i++) {
            int x;
            cin >> x;
            if (x == n) win=1;
        }
        for (int i=1;i<=b;i++) {
            int x;
            cin >> x;
            if (x == n) win=2;
        }
        if (win == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
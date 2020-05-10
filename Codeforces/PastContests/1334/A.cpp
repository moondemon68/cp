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
        int n;
        cin >> n;
        int x = 0, y = 0;
        bool ans = 1;
        for (int i=1;i<=n;i++) {
            int a,b;
            cin >> a >> b;
            if (a < b) ans = 0;
            if (a < x) ans = 0;
            if (b < y) ans = 0;
            if ((a-x) < (b-y)) ans = 0;
            x = a;
            y = b;
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
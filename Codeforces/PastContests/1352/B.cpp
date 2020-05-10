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
        int n,k;
        cin >> n >> k;
        if ((n-k+1)%2 == 1 && (n-k+1) > 0) {
            cout << "YES" << endl;
            for (int i=1;i<k;i++) cout << 1 << " ";
            cout << n-k+1 << endl;
        } else if ((n-2*k+2)%2 == 0 && (n-2*k+2) > 0) {
            cout << "YES" << endl;
            for (int i=1;i<k;i++) cout << 2 << " ";
            cout << n-2*k+2 << endl;
        } else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
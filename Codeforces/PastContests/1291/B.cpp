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
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int x = n, y = 1;
        for (int i=1;i<=n;i++) {
            if (a[i] < i-1) {
                x = i-1;
                break;
            }
        }
        for (int i=n;i>=1;i--) {
            if (a[i] < n-i) {
                y = i+1;
                break;
            }
        }
        // cout << x << " " << y << endl;
        if (x >= y) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
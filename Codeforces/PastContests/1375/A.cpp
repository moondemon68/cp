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
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            if (a[i] < 0) a[i] *= -1; 
        }
        for (int i=2;i<=n;i+=2) {
            if (a[i-1] > a[i] && a[i] > a[i+1]) a[i] *= -1;
            if (a[i-1] < a[i] && a[i] < a[i+1]) a[i] *= -1;
        }
        for (int i=1;i<=n;i++) cout << a[i] << " ";
        cout << endl;
        // cout << cntx << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
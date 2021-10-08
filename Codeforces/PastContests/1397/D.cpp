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
        int tot = 0;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            tot += a[i];
        }
        sort (a+1,a+n+1);
        if (a[n] > (tot-a[n])) cout << "T";
        else if (tot % 2 == 0) cout << "HL";
        else cout << "T";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
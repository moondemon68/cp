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
    int n = 10;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    LL p = 0, q = 0;
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            if ((i&j)) p += a[j]; else q += a[j];
        }
        if (p == q) cout << "ADA" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
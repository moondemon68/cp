#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << ' ' << 1 << endl;
        cout << -1 * a[1] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << " " << n << endl;
    for (LL i=1;i<=n;i++) cout << (1-a[i]-n)*n << " ";
    cout << endl;
    cout << 1 << " " << n-1 << endl;
    for (LL i=1;i<n;i++) cout << (a[i]+n)*(n-1) << " ";
    cout << endl;
    cout << n << " " << n << endl;
    cout << -1 * (a[n]+(1-a[n]-n)*n) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
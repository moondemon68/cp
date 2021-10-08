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
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        if (a[i] % m == 0) {
            cout << 1 << endl;
            cout << i << endl;
            return 0;
        }
        a[i] %= m;
    }
    a[0] = 0;
    int p[m+5];
    memset(p,-1,sizeof(p));
    for (int i=1;i<=n;i++) {
        a[i] += a[i-1];
        a[i] %= m;
        // cout << a[i] << " " << p[a[i]] << endl;
        if (p[a[i]] != -1) {
            cout << i-p[a[i]] << endl;
            for (int j=p[a[i]]+1;j<=i;j++) cout << j << " ";
            cout << endl;
            return 0;
        } else if (a[i] == 0) {
            cout << i << endl;
            for (int j=1;j<=i;j++) cout << j << " ";
            cout << endl;
            return 0;
        } else {
            p[a[i]] = i;
        }
    }
    cout << -1 << endl; // harusnya gaada
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
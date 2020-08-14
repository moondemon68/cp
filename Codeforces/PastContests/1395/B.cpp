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
    int n,m,sx,sy;
    cin >> n >> m >> sx >> sy;
    int a[n+5];
    for (int i=1;i<=n;i++) {
        a[i] = i;
    }
    swap(a[1], a[sx]);
    int b[m+5];
    for (int i=1;i<=m;i++) b[i] = i;
    swap(b[1], b[sy]);
    for (int i=1;i<=n;i++) {
        if (i%2 == 1) {
            for (int j=1;j<=m;j++) {
                cout << a[i] << " " << b[j] << endl;
            }
        } else {
            for (int j=m;j>=1;j--) {
                cout << a[i] << " " << b[j] << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
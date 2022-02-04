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

const int MAXN = 1e5;
LL a[MAXN+5], b[MAXN+5], c[MAXN+5];
LL sum = 0;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) {
        sum += b[i];
        c[i] = a[i];
    }
    sort(c+1,c+n+1);
    if (c[1] != c[n]) {
        for (int i=1;i<=n;i++) cout << sum << endl;
    } else {
        for (int i=1;i<=n;i++) cout << b[i] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
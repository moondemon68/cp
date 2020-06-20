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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans[n+5];
    bool d[2*n+5];
    memset (d,0,sizeof(d));
    d[a[n]] = 1;
    memset(ans,-1,sizeof(ans));
    for (int i=2;i<=n;i++) {
        if (a[i] > a[i-1]) {
            ans[i] = a[i-1];
            d[ans[i]] = 1;
        }
    }
    int x = 0;
    for (int i=1;i<=n;i++) {
        if (ans[i] == -1) {
            while (d[x]) x++;
            d[x] = 1;
            ans[i] = x;
        }
    }
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
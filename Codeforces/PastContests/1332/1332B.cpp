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
        for (int i=1;i<=n;i++) cin >> a[i];
        int ans[n+5];
        memset (ans,0,sizeof(ans));
        int x = 1;
        map<int,int> p;
        for (int i=1;i<=n;i++) {
            for (int j=2;j*j<=a[i];j++) {
                if (a[i] % j == 0) {
                    if (p[j] == 0) p[j] = x++;
                    ans[i] = p[j];
                    break;
                }
            }
        }
        cout << x-1 << endl;
        for (int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
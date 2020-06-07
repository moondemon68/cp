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
        for (int i=1;i<=n;i++) {
            ans[i] = max(1, ans[i]);
            for (int j=i+i;j<=n;j+=i) {
                if (a[j] > a[i]) ans[j] = max(ans[j], ans[i]+1);
            }
        }
        int p = 0;
        for (int i=1;i<=n;i++) p = max(ans[i], p);
        cout << p << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
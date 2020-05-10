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
        set<int> s;
        for (int i=1;i<=n;i++) s.insert(a[i]);
        if (s.size() == 1) {
            cout << 1 << endl;
            for (int i=1;i<=n;i++) cout << 1 << " ";
        } else if (s.size() == 2) {
            cout << 2 << endl;
            for (int i=1;i<=n;i++) {
                if (a[i] == a[1]) cout << 1 << " ";
                else cout << 2 << " ";
            }
        } else if (n % 2 == 0) {
            cout << 2 << endl;
            for (int i=1;i<=n;i++) cout << 2 - (i%2) << " ";
        } else {
            int ans[n+5];
            memset (ans,0,sizeof(ans));
            int cnt = 0, x = 0;
            a[n+1] = a[1];
            for (int i=1;i<=n;i++) {
                if (a[i] == a[i+1]) {
                    cnt++;
                    x = i;
                }
            }
            if (cnt >= 1) {
                ans[x] = 1;
                ans[x+1] = 1;
                if (x == n) ans[1] = 1;
                for (int j=x-1;j>=1;j--) {
                    if (ans[j] == 0) ans[j] = 3 - ans[j+1];
                }
                for (int j=x+1;j<=n;j++) {
                    if (ans[j] == 0) ans[j] = 3 - ans[j-1];
                }
                cout << 2 << endl;
                for (int i=1;i<=n;i++) cout << ans[i] << " ";
            } else {
                cout << 3 << endl;
                for (int i=1;i<n;i++) cout << 2 - (i%2) << " ";
                cout << 3;
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
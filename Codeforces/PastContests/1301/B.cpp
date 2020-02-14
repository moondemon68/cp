#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
        a[n+1] = -1;
        a[0] = -1;
        vector<int> b;
        for (int i=1;i<=n;i++) {
            if (a[i] == -1 && a[i+1] != -1) b.pb(a[i+1]);
            if (a[i] == -1 && a[i-1] != -1) b.pb(a[i-1]);
        }
        sort (b.begin(), b.end());
        int p = 0;
        if ((int)b.size() == 0) p = 0;
        else p = (b[0] + b[b.size()-1])/2;
        for (int i=1;i<=n;i++) {
            if (a[i] == -1) {
                a[i] = p;
            }
        }
        int ans = 0;
        for (int i=1;i<n;i++) {
            ans = max(ans, abs(a[i]- a[i+1]));
        }
        cout << ans << " " << p << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
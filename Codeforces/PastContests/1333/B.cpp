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
        int a[n+5],b[n+5],need[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        for (int i=1;i<=n;i++) need[i] = b[i]-a[i];
        int mins = 0, plus = 0, ans = 1;
        for (int i=1;i<=n;i++) {
            if (need[i] == 0) {
                if (a[i] == -1) mins = 1;
                else if (a[i] == 1) plus = 1;
            } else {
                if (need[i] > 0 && plus == 0) {
                    ans = 0;
                }
                if (need[i] < 0 && mins == 0) {
                    ans = 0;
                }
                if (a[i] == -1) mins = 1;
                else if (a[i] == 1) plus = 1;
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
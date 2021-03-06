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
        int n,s,k;
        cin >> n >> s >> k;
        map<int,int> p;
        for (int i=1;i<=k;i++) {
            int x;
            cin >> x;
            p[x]=1;
        }
        int ans = INT_MAX;
        for (int i=s;i>=1;i--) {
            if (!p[i]) {
                ans = min(ans, abs(s-i));
                break;
            }
        }
        for (int i=s;i<=n;i++) {
            if (!p[i]) {
                ans = min(ans, abs(s-i));
                break;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
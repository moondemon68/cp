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
        vector<int> ans;
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        
        for (int i=n-1;i>=0;i--) {
            if (a[i] == b[i]) continue;
            else {
                ans.pb(i+1);
                if (a[i] != b[n-i-1]) {
                    ans.pb(1);
                }
                ans.pb(i+1);
            }
        }
        cout << ans.size() << " ";
        int p[n+5];
        memset (p,0,sizeof(p));
        for (auto x : ans) {
            for (int i=1;i<=x;i++) p[i]++;
            cout << x << " ";
        }
        cout << endl;
        for (int i=1;i<=n;i++) cout << p[i]/2 << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
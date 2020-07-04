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
        for (int i=0;i<n;i++) cin >> a[i];
        vector<int> ans;
        for (int i=0;i<n;i++) {
            if (a[i] == i) continue;
            bool y = 1;
            for (int j=i;j<n-1;j++) {
                if (a[j] > a[j+1]) y = 0;
            }
            if (y) break;
            set<int> s;
            for (int j=0;j<n;j++) {
                s.insert(a[j]);
            }
            int mex = 0;
            while (s.find(mex) != s.end()) mex++;
            for (int j=n-1;j>=i+1;j--) {
                if (a[j] == i) {
                    ans.pb(j+1);
                    a[j] = mex;
                    s.insert(a[j]);
                    while (s.find(mex) != s.end()) mex++;
                }
            }

            set<int> tt;
            for (int j=0;j<n;j++) {
                tt.insert(a[j]);
            }
            int x = 0;
            while (tt.find(x) != tt.end()) x++;
            
            ans.pb(i+1);
            a[i] = x;
        }
        if (a[n-1] < a[n-2]) {
            ans.pb(n);
        }
        if (ans.size() > 2*n) while(1);
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
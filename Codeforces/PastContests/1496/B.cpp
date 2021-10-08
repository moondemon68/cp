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
        int n,k;
        cin >> n >> k;
        set<int> s;
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        int prev = s.size();
        bool y = 0;
        while (k--) {
            int cur = 0, maxi = 0;
            for (auto x : s) {
                if (x == cur) {
                    cur++;
                }
                maxi = max(maxi, x);
            }
            s.insert((cur + maxi + 1) / 2);
            if (prev == s.size()) break;
            prev = s.size();
            if (cur == maxi + 1) {
                cout << s.size() + k << endl;
                y = 1;
                break;
            }
        }
        if (!y) cout << s.size() << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
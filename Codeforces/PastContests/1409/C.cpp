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
        int n,x,y;
        cin >> n >> x >> y;
        set<int> ans;
        for (int i=1;i<=50;i++) {   // diff
            set<int> tmp;
            int p = y;
            while (p >= 1 && tmp.size() < n) {
                tmp.insert(p);
                p -= i;
            }
            p = y + i;
            while (tmp.size() < n) {
                tmp.insert(p);
                p += i;
            }
            if (tmp.find(x) != tmp.end()) {
                ans = tmp;
                break;
            }
        }
        for (auto p : ans) cout << p << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
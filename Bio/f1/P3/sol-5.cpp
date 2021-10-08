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

vector<pii> v[500104+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // string testname = "0-test";
    string testname = "test5";
    ifstream cin(testname + "");
    ofstream cout(testname + ".out");
    int tc;
    cin >> tc;
    while (tc--) {
        int n, d;
        cin >> n >> d;
        double cnt[n+5];
        memset(cnt,0,sizeof(cnt));
        bool kena[n+5];
        memset(kena,0,sizeof(kena));
        int par[n+5];
        while (d--) {
            int x;
            cin >> x;
            while (x--) {
                int u,v;
                double w;
                cin >> u >> v >> w;
                cnt[u] += w;
            }
        }
        int maxi = 0, ans = 0;
        for (int i=1;i<=n;i++) {
            if (cnt[i] > maxi) {
                maxi = cnt[i];
                ans = i;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
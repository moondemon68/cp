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
    ifstream cin("2.txt");
    ofstream cout("2out.txt");
    int tc;
    cin >> tc;
    while (tc--) {
        int m,k,n;
        cin >> m >> k >> n;
        double a[m+5], b[k+5];
        for (int i=1;i<=m;i++) cin >> a[i];
        for (int i=1;i<=k;i++) cin >> b[i];
        while (n--) {
            pii ans = {-1, -1};
            double mini = 1e9;
            double x;
            cin >> x;
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= k; j++) {
                    if ((a[i] + b[j]) > 0 && abs(x - a[i] - b[j]) < mini)  {
                        mini = abs(x - a[i] - b[j]);
                        ans = {i, j};
                    }
                }
            }
            cout << ans.fi << " " << ans.se << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
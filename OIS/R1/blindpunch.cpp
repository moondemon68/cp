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
        int n,k;
        cin >> n >> k;
        priority_queue<pair<double,int>> p;
        double g[n+5];
        for (int i=1;i<=n;i++) {
            double x;
            cin >> x;
            p.push(mp(x,i));
            g[i] = 1-x;
        }
        double ans=0;
        while (k--) {
            pair<double,int> x = p.top();
            p.pop();
            ans+=x.fi;
            p.push(mp(x.fi*g[x.se], x.se));
        }
        ans = floor(ans * 1000000) / 1000000;
        printf("%.6f\n", ans);
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
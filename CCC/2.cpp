#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (LL t=1;t<=5;t++) {
        ifstream cin("level2/level2_" + to_string(t) + ".in");
        ofstream cout("level2/level2_" + to_string(t) + ".out");
        LL n;
        cin >> n;
        LL a[n+5];
        a[0] = 0;
        for (LL i=1;i<=n;i++) cin >> a[i];
        for (LL i=2;i<=n;i++) a[i] += a[i-1];
        LL m;
        cin >> m;
        cout << m << '\n';
        for (LL i=1;i<=m;i++) {
            LL p,x;
            cin >> p >> x;
            LL mini = INT_MAX, minx = 0;
            for (LL j=1;j<=n-x+1;j++) {
                if (a[j+x-1]-a[j-1] < mini) {
                    mini = a[j+x-1]-a[j-1];
                    minx = j;
                }
            }
            // cout << mini << " ";
            cout << p << " " << minx - 1 << '\n';
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
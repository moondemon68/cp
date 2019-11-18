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
        double xa,ya,xb,yb,xc,yc,r,d1,d2,ans;
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> r;
        d1 = abs(sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc)) - r);    // A outside
        d2 = abs(sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc)) - r);    // B outside

        double dist = sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));    // AB outside, not pass circle
        if (sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc)) <= r && sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc)) <= r) {
            ans = 0;
        } else if (sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc)) <= r) {
            ans = d2;
        } else if (sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc)) <= r) {
            ans = d1;
        } else {
            ans= min(d1+d2, dist);
        }

        ans = floor(ans * 1000000) / 1000000;
        printf("%.6f\n", ans);
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
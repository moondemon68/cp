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

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    if (a.fi.se == b.fi.se) {
        return a.fi.fi <= b.fi.fi;
    } else {
        return a.fi.se < b.fi.se;
    }
}
pair<pii, int> a[100005];
int ans[100005];

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
        for (int i=1;i<=n;i++) {
            cin >> a[i].fi.fi >> a[i].fi.se;
            a[i].se = i;
        }
        sort(a+1,a+n+1,cmp);
        memset(ans,0,sizeof(ans));
        bool y = 1;
        for (int i=1;i<=n;i++) {
            for (int j=a[i].fi.fi;j<=a[i].fi.se;j++) {
                if (ans[j] == 0) {
                    ans[j] = a[i].se;
                    break;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            if (ans[i] == 0) y = 0;
        }
        if (y) {
            for (int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
4
3 3
1 3
2 2
2 4

2 3 1 4

2 2
1 3
3 3
2 4
*/
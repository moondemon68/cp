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
    int n;
    cin >> n;
    vector<pii> a;
    for (int i=1;i<=4*n+1;i++) {
        int x,y;
        cin >> x >> y;
        a.pb(mp(x,y));
    }
    
    for (int i=0;i<=50;i++) {
        for (int j=0;j<=50;j++) {
            for (int p=1;p<=50;p++) {
                vector<pii> ans;
                for (int k=0;k<(int)a.size();k++) {
                    if ((a[k].fi>i&&a[k].fi<i+p&&a[k].se>j&&a[k].se<j+p)||(a[k].fi<i)||a[k].fi>i+p||a[k].se<j||a[k].se>j+p) ans.pb(a[k]);
                }
                if (ans.size()==1) {
                    //cout << i << j << p << endl;
                    cout << ans[0].fi << " " << ans[0].se << endl;
                    return 0;
                }
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#include <bits/stdc++.h>
#define fi first.first
#define se first.second
#define id second
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
    int n,m;
    cin >> n >> m;
    pair<pii,int> a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].id=i;
    }
    sort (a+1,a+n+1);
    int x=1,p=1;
    vector<int> ans;
    while (x<=m&&p<=n) {
        int g=0,maxi=0;
        while (a[p].fi<=x&&p<=n) {
            if (a[p].se>maxi) {
                maxi=a[p].se;
                g=a[p].id;
            }
            p++;
        }
        if (g==0) {
            cout << "NO" << endl;
            return 0;
        } else {
            ans.pb(g);
            x=maxi+1;
        }
    }
    if (x!=m+1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
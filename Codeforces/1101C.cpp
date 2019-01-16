#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool cmp(pair<pair<int,int>,int> a,pair<pii,int> b) {
    return a.fi.se<b.fi.se;
}

pair<pair<int,int>,int> a[100005];
int ans[100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) {
            a[i].se=i;
            cin >> a[i].fi.fi >> a[i].fi.se;
        }
        sort (a+1,a+n+1,cmp);
        memset (ans,0,sizeof(ans));
        for (int i=n-1;i>=1;i--) {
            a[i].fi.fi=min(a[i+1].fi.fi,a[i].fi.fi);
        }
        bool y=0;
        for (int i=1;i<n;i++) {
            //cout << a[i].fi.fi << " " << a[i].fi.se << endl;
            if (a[i].fi.se<a[i+1].fi.fi) {
                for (int j=1;j<=i;j++) ans[a[j].se]=1;
                for (int j=i+1;j<=n;j++) ans[a[j].se]=2;
                y=1;
                break;
            }
        }
        if (!y) cout << -1;
        else for (int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }    
    return 0;
}

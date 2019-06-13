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

bool cmp(pair<pii,int> a,pair<pii,int> b) {
    if (a.se==b.se) return a.fi<b.fi;
    return a.se>b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    vector<pair<pii,int>> p;
    for (int i=1;i<=n;i++) p.pb(mp(mp(a[i],b[i]),i));
    sort (p.begin(),p.end(),cmp);
    int ans[n+5];
    ans[p[0].id]=0;
    for (int i=1;i<p.size();i++) {
        //cout << p[i].fi << p[i].se << p[i].id << endl;
        for (int j=i-1;j>=0;j--) {
            if (p[i].fi>p[j].fi) {
                ans[p[i].id]=p[j].id;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++) cout << ans[i] << ' ';
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
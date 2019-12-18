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
    int n;
    cin >> n;
    int d[n+5];
    for (int i=1;i<=n;i++) cin >> d[i];
    vector<int> v;
    v.pb(0);
    for (int i=1;i<=n;i++) v.pb(2*i-1);
    vector<pii> ans;
    for (int i=1;i<v.size()-1;i++) ans.pb({v[i],v[i+1]});
    for (int i=1;i<=n;i++) {
        if (i+d[i]-1==v.size()-1) v.pb(2*i);
        ans.pb({2*i,v[i+d[i]-1]});
    }
    //for (int i=1;i<v.size();i++) cout << v[i];
    for (int i=0;i<ans.size();i++) cout << ans[i].fi << " " << ans[i].se << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
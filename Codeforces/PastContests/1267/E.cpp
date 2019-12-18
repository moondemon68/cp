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
    int n,m;
    cin >> n >> m;
    int a[m+5][n+5];
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    vector<int> ans;
    for (int i=1;i<n;i++) {
        vector<pii> v;
        for (int j=1;j<=m;j++) {
            v.pb(mp(a[j][i]-a[j][n], j));
        }
        sort (v.begin(), v.end());
        reverse(v.begin(), v.end());
        //for (int j=0;j<v.size();j++) cout << v[j].fi << " ";
        int cnt=0;
        vector<int> tmp;
        for (int j=0;j<v.size();j++) {
            if (cnt + v[j].fi < 0) break;
            cnt+=v[j].fi;
            tmp.pb(v[j].se);
        }
        //cout << tmp.size() << endl;
        if (tmp.size() > ans.size()) {
            ans.clear();
            for (int j=0;j<tmp.size();j++) ans.pb(tmp[j]);
        }
    }
    bool b[m+5];
    memset (b,0,sizeof(b));
    for (int i=0;i<ans.size();i++) b[ans[i]] = 1;
    cout << m - ans.size() << endl;
    for (int i=1;i<=m;i++) {
        if (!b[i]) cout << i << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
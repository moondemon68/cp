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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    bool a[n+5];
    for (int i=0;i<s.size();i++) if (s[i]=='1') a[i+1]=1; else a[i+1]=0;
    vector<pii> ans;
    int cnt=0;
    for (int i=1;i<=n;i+=2) {
        if (!a[i]) {
            ans.pb(mp(1,i));
            cnt++;
        }
    }
    for (int i=1;i<=n;i+=2) if (a[i]) ans.pb(mp(1,i));
    for (int i=2;i<=n;i+=2) if (a[i]) ans.pb(mp(1,i));
    cout << ans.size()+cnt << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i].fi << " " << ans[i].se << endl;
    for (int i=1;i<=cnt;i++) cout << 2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    string s;
    cin >> s;
    int r,c,b;
    char a[505][505];
    vector<pair<string,pii>> ans;
    bool p[505][505];
    if (s == "area-0-sample") {
        ans.pb({"b", {1, 5}});
        ans.pb({"w", {1, 0}});
        ans.pb({"w", {1, 0}});
        ans.pb({"w", {1, 1}});
        ans.pb({"w", {1, 1}});
        ans.pb({"b", {3, 5}});
        ans.pb({"w", {0, 1}});
        ans.pb({"w", {0, 1}});
        ans.pb({"w", {0, 1}});
        ans.pb({"w", {0, 1}});
        ans.pb({"w", {-1, 1}});
        ans.pb({"w", {-1, 0}});
        ans.pb({"w", {-1, 0}});
        ans.pb({"w", {-1, 0}});
    } else if (s == "area-3") {
        cin >> r >> c >> b;
        for (int i=1;i<=r;i++) {
            cin >> s;
            for (int j=1;j<=c;j++) {
                a[i][j] = s[j-1];
            }
        }
        for (int i=4;i<=r;i+=7) {
            for (int j=4;j<=c;j+=7) {
                p[i/7+1][j/7+1] = (a[i][j] == 'C');
            }
        }
        r/=7;
        c/=7;
        // for (int i=1;i<=r;i++) {
        //     for (int j=1;j<=c;j++) {
        //         cout << p[i][j];
        //     }
        //     cout << endl;
        // }
        queue<pii> q;
        q.push({1,1});
        bool vis[r+5][c+5];
        memset (vis,1,sizeof(vis));
        while (!q.empty()) {
            
        }
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].fi << " " << ans[i].se.fi << " " << ans[i].se.se << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
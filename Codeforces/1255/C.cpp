#include <bits/stdc++.h>
#define x first
#define y second.first
#define z second.second
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
    int cnt[n+5];
    memset (cnt,0,sizeof(cnt));
    pair<int, pii> a[n+5];
    map<pii, vector<int>> m;
    for (int i=1;i<=n-2;i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        cnt[a[i].x]++;
        cnt[a[i].y]++;
        cnt[a[i].z]++;
        m[mp(a[i].x, a[i].y)].pb(a[i].z);
        m[mp(a[i].x, a[i].z)].pb(a[i].y);
        m[mp(a[i].y, a[i].x)].pb(a[i].z);
        m[mp(a[i].y, a[i].z)].pb(a[i].x);
        m[mp(a[i].z, a[i].x)].pb(a[i].y);
        m[mp(a[i].z, a[i].y)].pb(a[i].x);
    }
    pii c[n+5];
    for (int i=1;i<=n;i++) c[i]=mp(cnt[i], i);
    sort (c+1,c+n+1);
    // for (int i=1;i<=n;i++) cout << c[i].first << " " << c[i].second << endl;
    vector<int> ans;
    int p = 1;
    bool done[n+5];
    memset(done,0,sizeof(done));
    ans.pb(c[1].second);
    done[c[1].second]=1;
    ans.pb(c[3].second);
    done[c[3].second]=1;
    bool consistent = 1;
    for (int i=1;i<=n-2;i++) {
        int find = 0;
        for (int i=0;i<m[mp(ans[ans.size()-1], ans[ans.size()-2])].size();i++) {
            if (!done[m[mp(ans[ans.size()-1], ans[ans.size()-2])][i]]) find = m[mp(ans[ans.size()-1], ans[ans.size()-2])][i];
        }
        ans.pb(find);
        done[find] = 1;
        if (find == 0) {
            consistent = 0;
            break;
        }
    }
    if (consistent) {
        for (int i=0;i<ans.size();i++) {
            cout << ans[i] << " ";
        }
        return 0;
    }
    memset(done,0,sizeof(done));
    ans.clear();
    ans.pb(c[1].second);
    done[c[1].second]=1;
    ans.pb(c[4].second);
    done[c[4].second]=1;
    consistent = 1;
    for (int i=1;i<=n-2;i++) {
        int find = 0;
        for (int i=0;i<m[mp(ans[ans.size()-1], ans[ans.size()-2])].size();i++) {
            if (!done[m[mp(ans[ans.size()-1], ans[ans.size()-2])][i]]) find = m[mp(ans[ans.size()-1], ans[ans.size()-2])][i];
        }
        ans.pb(find);
        done[find] = 1;
        if (find == 0) {
            consistent = 0;
            break;
        }
    }
    if (consistent) {
        for (int i=0;i<ans.size();i++) {
            cout << ans[i] << " ";
        }
        return 0;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
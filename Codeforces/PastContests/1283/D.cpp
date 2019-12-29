#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    map<LL,int> s;
    vector<LL> ans;
    LL cnt=0;
    queue<pair<LL,LL>> q;
    for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        s[x] = 1;
        q.push({x, 0});
    }
    LL d=1;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        pii next = {cur.fi-1, cur.se+1};
        if (s[next.fi] == 0) {
            q.push(next);
            ans.pb(next.fi);
            cnt += next.se;
            s[next.fi] = 1;
        }
        if (ans.size() == m) break;
        next = {cur.fi+1, cur.se+1};
        if (s[next.fi] == 0) {
            q.push(next);
            ans.pb(next.fi);
            cnt += next.se;
            s[next.fi] = 1;
        }
        if (ans.size() == m) break;
    }

    cout << cnt << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
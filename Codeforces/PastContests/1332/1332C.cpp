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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> adj[n+5];
        for (int i=0;i<k;i++) {
            for (int j=1;j<n/k;j++) {
                adj[(j-1)*k+i].pb(j*k+i);
                adj[j*k+i].pb((j-1)*k+i);
            }
        }
        for (int i=0;i<s.size();i++) {
            adj[i].pb(s.size()-i-1);
        }
        // for (int i=0;i<s.size();i++) {
        //     cout << i << " -> ";
        //     for (auto x : adj[i]) cout << x << " ";
        //     cout << endl;
        // }
        int vis[n+5];
        memset (vis,0,sizeof(vis));
        int x = 1, ans = 0;
        for (int i=0;i<s.size();i++) {
            if (vis[i] == 0) {
                int cnt[30];
                memset (cnt,0,sizeof(cnt));
                cnt[s[i]-'a']++;
                vis[i] = x;
                x++;
                stack<int> p;
                p.push(i);
                while (!p.empty()) {
                    int cur = p.top();
                    p.pop();
                    for (auto next : adj[cur]) {
                        if (vis[next] == 0) {
                            cnt[s[next]-'a']++;
                            vis[next] = vis[i];
                            p.push(next);
                        }
                    }
                }
                int maxi = 0, tot = 0;
                for (int j=0;j<26;j++) {
                    maxi = max(maxi, cnt[j]);
                    tot += cnt[j];
                }
                ans += tot - maxi;
            }
        }
        // for (int i=0;i<s.size();i++) cout << vis[i] << " ";
        cout << ans << endl;

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

int convert(string l) {
    int x = 0, y = 0;
    if (l.size() >= 3 && l[2] == '+') {
        for (int i=5;i<l.size();i++) {
            y += l[i] - '0';
            y *= 10;
        }
        y /= 10;
        x = 1;
        for (int i=1;i<=l[3]-'0';i++) {
            x *= 10;
        }
        x += y;
    } else {
        for (int i=0;i<l.size();i++) {
            x += l[i] - '0';
            x *= 10;
        }
        x /= 10;
    }
    return x;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> v;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        v.pb(s);
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        string l;
        cin >> k >> l;
        int times = convert(l);
        times++;
        vector<int> adj[n+5];
        for (int i=1;i<=k;i++) {
            int x,y;
            string p;
            cin >> x >> p >> y;
            adj[x].pb(y);
        }
        pii vis[n+5];
        memset(vis,0,sizeof(vis));
        int sz[n+5];
        vector<int> a[n+5];
        for (int i=1;i<=n;i++) {
            if (vis[i].fi == 0) {
                queue<int> q;
                q.push(i);
                vis[i] = {i, 1};
                sz[i] = 1;
                a[i].pb(i);
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (auto next : adj[cur]) {
                        if (vis[next].fi == 0) {
                            q.push(next);
                            vis[next] = {i, vis[cur].se + 1};
                            sz[i] = vis[next].se;
                            a[i].pb(next);
                        }
                    }
                }
            }
        }
        // for (int i=1;i<=n;i++) {
        //     if (vis[i].fi != 0 && !a[i].empty()) {
        //         cout << sz[i] << " -> ";
        //         for (auto x : a[i]) cout << x << " ";
        //         cout << endl;
        //     }
        // }
        for (int i=1;i<=n;i++) {
            cout << v[a[vis[i].fi][(vis[i].se + times)%sz[vis[i].fi]] - 1] << " ";
            // cout << v[a[(vis[i].se + times)%sz[vis[i].fi]]] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
6
time space reality power soul mind
3
4 1
1 -> 2
2 -> 1
4 -> 6
6 -> 4
2 13
2 -> 4
4 -> 2
6 10e6+4
1 -> 2
2 -> 3
3 -> 4
4 -> 5
5 -> 6
6 -> 1
*/
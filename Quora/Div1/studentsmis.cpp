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

const int MAXN = 3005;
const int MAXN2 = 200005;

// vector<int> adj[MAXN * MAXN + 5];
// int vis[MAXN * MAXN + 5];
vector<int> adj[MAXN2 * 2 + 5];
int vis[MAXN2 * 2 + 5];
int n, m;

vector<int> adj2[MAXN2];
int match[MAXN2];
bool vis2[MAXN2];
int ckiri, ckanan;
int comp[MAXN2];

map<pii, int> compressAwal;
int compress = 0;

bool dfs(int node){
	if(vis2[node])return 0;
	vis2[node] = 1;
	for(auto nx:adj2[node]){
		if(match[nx]==-1 || dfs(match[nx])){
			match[node] = nx;
			match[nx] = node;
			return 1;
		}
	}
	return 0;
}
void cal(int node){
    if(vis2[node])return;
    vis2[node] = 1;
    if(node>ckiri){     // node from the right side, can only traverse matched edge
        cal(match[node]);
        return;
    }
    for(auto nx:adj2[node]){
        if(nx==match[node])continue;
        cal(nx);
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        x2--; y2--;
        if (compressAwal[{x1, y1}] == 0) {
            compress++;
            compressAwal[{x1, y1}] = compress;
        }
        if (compressAwal[{x2, y2}] == 0) {
            compress++;
            compressAwal[{x2, y2}] = compress;
        }
        adj[compressAwal[{x1, y1}]].pb(compressAwal[{x2, y2}]);
        adj[compressAwal[{x2, y2}]].pb(compressAwal[{x1, y1}]);
    }
    // for (int k=1;k<=compress;k++) {
    //     if (!adj[k].empty()) {
    //         cout << k << " -> ";
    //         for (auto x : adj[k]) cout << x << " ";
    //         cout << endl;
    //     }
    // }
    int ans = 0;
    memset(vis,-1,sizeof(vis));
    for (int k=1;k<=compress;k++) {
        if (vis[k] != -1) continue;
        stack<int> s;
        s.push(k);
        vis[k] = 1;
        int black = 1, white = 0;
        vector<int> bs, ws;
        bs.pb(k);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (auto next : adj[cur]) {
                if (vis[next] == -1) {
                    vis[next] = 1 - vis[cur];
                    if (vis[next] == 1) {
                        black++;
                        bs.pb(next);
                    } else {
                        white++;
                        ws.pb(next);
                    }
                    s.push(next);
                }
            }
        }
        
        ckiri = 0;
        ckanan = 0;
        for (auto x : bs) {
            ckiri++;
            comp[x] = ckiri;
        }
        for (auto x : ws) {
            ckanan++;
            comp[x] = ckanan + ckiri;
        }
        // cout << ckiri << " " << ckanan << endl;
        for (int i=1;i<=ckiri + ckanan;i++) {
            adj2[i].clear();
        }
        for (auto x : bs) {
            for (auto p : adj[x]) {
                adj2[comp[x]].pb(comp[p]);
            }
        }
        for (auto x : ws) {
            for (auto p : adj[x]) {
                adj2[comp[x]].pb(comp[p]);
            }
        }
        // for (int i=1;i<=5000;i++) {
        //     if (!adj2[i].empty()) {
        //         cout << i << " -> ";
        //         for (auto x : adj2[i]) cout << x << " ";
        //         cout << endl;
        //     }
        // }


        memset(match, -1, sizeof match);
        while(1){
            memset(vis2, 0, sizeof vis2);
            bool cont = 0;
            for(int i=1;i<=ckiri;i++){
                if(match[i]==-1)cont|=dfs(i);
            }
            if(cont==0)break;
        }
        memset(vis2,0,sizeof vis2);
        for(int i=1;i<=ckiri;i++){
            if(match[i]!=-1)continue;       // matched node from the left side
            cal(i);
        }
        for (int i=1;i<=ckiri;i++) {
            if (vis2[i]) ans++;
        }
        for (int i=ckiri+1;i<=ckiri+ckanan;i++) {
            if (!vis2[i]) ans++;
        }
    }
    ans += n * n - compress;
    
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL fastPow(LL a,LL x,LL m) {
    LL ret=1;
    while (x>0) {
        if (x&1) {
            ret*=a;
            ret%=m;
        }
        x=x>>1;
        a*=a;
        a%=m;
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    int u[n+5],v[n+5],x[n+5];
    for (int i=1;i<n;i++) cin >> u[i] >> v[i] >> x[i];
    vector<int> adj[n+5];
    for (int i=1;i<n;i++) {
        if (!x[i]) {
            adj[u[i]].pb(v[i]);
            adj[v[i]].pb(u[i]);
        }
    }
    stack<int> s;
    LL ans=0;
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            LL sz=0;
            s.push(i);
            vis[i]=1;
            while (!s.empty()) {
                sz++;
                int cur=s.top();
                s.pop();
                for (int j=0;j<adj[cur].size();j++) {
                    int next=adj[cur][j];
                    if (!vis[next]) {
                        vis[next]=1;
                        s.push(next);
                    }
                }
            }
            //cout << sz << endl;
            ans+=fastPow(sz,k,MOD);
        }
    }
    //cout << ans << endl;
    ans=fastPow(n,k,MOD)-ans;
    while (ans<0) ans+=MOD;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
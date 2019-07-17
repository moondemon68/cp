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

bool overlap(vector<int> l1,vector<int> r1,vector<int> l2,vector<int> r2) {
    for (int i=0;i<l1.size();i++) {
        for (int j=0;j<l2.size();j++) {
            if (max(l1[i],l2[j])<=min(r1[i],r2[j])) return 1;
        }
    }
    return 0;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s,r;
    cin >> n >> s >> r;
    vector<int> a[n+5];
    vector<int> b[n+5];
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        for (int j=1;j<=x;j++) {
            int p,q;
            cin >> p >> q;
            a[i].pb(p);
            b[i].pb(q);
        }
    }
    vector<int> adj[n+5];
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (overlap(a[i],b[i],a[j],b[j])) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    /*
    for (int i=1;i<=n;i++) {
        cout << i << " ";
        for (int j=0;j<adj[i].size();j++) cout << adj[i][j] << " ";
        cout << endl;
    }
    */
    int vis[n+5];
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (vis[i]!=0) continue;
        vis[i]=1;
        stack<int> s;
        s.push(i);
        vector<int> v;
        v.pb(i);
        while (!s.empty()) {
            int cur=s.top();
            s.pop();
            for (int j=0;j<adj[cur].size();j++) {
                int next=adj[cur][j];
                if (vis[next]==0) {
                    vis[next]=1;
                    v.pb(next);
                    s.push(next);
                }
            }
        }
        for (int j=0;j<v.size();j++) {
            vis[v[j]]=v.size();
        }
    }
    while (r--) {
        int x;
        cin >> x;
        cout << vis[x] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
// Lowest Common Ancestor - Euler+Segtree
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> tour;
vector<int> tinggi;
vector<int> adj[1005];
bool vis[1005];
int first_appear[1005],height[1005];
int seg[20005];

void dfs(int v,int h) {
    vis[v]=1;
    tour.pb(v);
    tinggi.pb(h);
    for (int i=0;i<adj[v].size();i++) {
        if (!vis[adj[v][i]]) dfs(adj[v][i],h+1);
        tour.pb(v);
        tinggi.pb(h);
    }
}

void build (int p,int s,int e) {
    if (s==e) {
        seg[p]=tour[e];
    } else {
        int m=(s+e)/2;
        build(2*p,s,m);
        build(2*p+1,m+1,e);
        int l=seg[2*p],r=seg[2*p+1];
        if (height[l]<height[r]) seg[p]=l; else seg[p]=r;
    }
}

int find_min(int p,int s,int e,int l,int r) {
    if (s>=l&&e<=r) return seg[p];
    if (s>r||e<l) return -1;
    int m=(s+e)/2;
    int left=find_min(2*p,s,m,l,r),right=find_min(2*p+1,m+1,e,l,r);
    if (left==-1) return right;
    if (right==-1) return left;
    if (height[left]<height[right]) return left; else return right;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        tour.clear();
        tinggi.clear();
        memset (vis,0,sizeof(vis));
        memset (first_appear,-1,sizeof(first_appear));
        memset (seg,-1,sizeof(seg));
        memset (height,-1,sizeof(height));
        for (int i=1;i<=2000;i++) adj[i].clear();
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) {
            int m;
            cin >> m;
            for (int j=1;j<=m;j++) {
                int x;
                cin >> x;
                adj[i].pb(x);
                adj[x].pb(i);
            }
        }
        dfs(1,1);
        //for (int i=0;i<(int)tour.size();i++) cout << tour[i] << " ";
        //cout << endl;
        //for (int i=0;i<(int)tinggi.size();i++) cout << tinggi[i] << " ";
        //cout << endl;
        for (int i=0;i<(int)tour.size();i++) {
            if (first_appear[tour[i]]==-1) first_appear[tour[i]]=i;
            height[tour[i]]=tinggi[i];
        }
        //for (int i=1;i<=n;i++) cout << height[i] << " ";
        //cout << endl;
        build(1,0,(int)tour.size()-1);
        int q;
        cin >> q;
        cout << "Case " << t << ":" << endl;
        for (int i=1;i<=q;i++) {
            int u,v;
            cin >> u >> v;
            int l=first_appear[u],r=first_appear[v];
            //cout << l << r << endl;
            cout << find_min(1,0,(int)tour.size()-1,min(l,r),max(l,r)) << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
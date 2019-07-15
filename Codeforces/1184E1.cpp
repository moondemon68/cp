#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pqg priority_queue<long long, vector<long long>, greater<long long> >
#define pql priority_queue<long long>
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
    
// problem : Problem IIT Challenge "Dracula" on cp.if.itb.ac.id
// https://w...content-available-to-author-only...s.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/
// https://w...content-available-to-author-only...s.org/prims-algorithm-using-priority_queue-stl/
    
ll n, m, u, v, w;
int s = 1; // let this be the source of the vertex
int u1,v1;
bool extraCheck(vector<pll> a[],long long mst) {
    for (int i=0;i<(int)a[u1].size();i++) {
        if (a[u1][i].ff==v1) a[u1][i].ss=1234567890;
    }
    for (int i=0;i<(int)a[v1].size();i++) {
        if (a[v1][i].ff==u1) a[v1][i].ss=1234567890;
    }
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    
    // create a vector key and initialize all of it to inf
    vector<ll> key(n+2,inf);
    
    // to store a parent which in turn store MST (optional)
    vector<ll> parent(n+2,-1);
    
    // To keep track of vertices included in MST
    vector<bool> inMST(n+2,false);
    
    pq.push(mp(0,s));
    key[s] = 0;
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();
    
        // include vertex u to the MST
        inMST[u] = true;
    
        for(int j=0; j<(int)a[u].size();j++){
            int v = a[u][j].ff;
            int weight = a[u][j].ss;
    
            // if v is not yet in MST and weight of (u,v) is smaller
            // than the current key of v
            if(inMST[v] == false && key[v] > weight){
                // update the key[v]
                key[v] = weight;
                pq.push(mp(key[v],v));
                parent[v] = u;
            }
        }
    }
    long long mst2=0;
    // print edges of MST using parent array
    bool y=0;
    for (int i=1;i<=n;i++){
        //cout << i << " => " << parent[i] << " => " << key[i] << "\n";
        if ((i==u1&&parent[i]==v1)||(i==v1&&parent[i]==u1)) y=1;
        mst2+=key[i];
    }
    if (mst==mst2) return 0; else return 1;
}
bool minSpanningTree(vector<pll> a[],int weight){
    a[u1].pb(mp(v1,weight));
    a[v1].pb(mp(u1,weight));
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    
    // create a vector key and initialize all of it to inf
    vector<ll> key(n+2,inf);
    
    // to store a parent which in turn store MST (optional)
    vector<ll> parent(n+2,-1);
    
    // To keep track of vertices included in MST
    vector<bool> inMST(n+2,false);
    
    pq.push(mp(0,s));
    key[s] = 0;
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();
    
        // include vertex u to the MST
        inMST[u] = true;
    
        for(int j=0; j<(int)a[u].size();j++){
            int v = a[u][j].ff;
            int weight = a[u][j].ss;
    
            // if v is not yet in MST and weight of (u,v) is smaller
            // than the current key of v
            if(inMST[v] == false && key[v] > weight){
                // update the key[v]
                key[v] = weight;
                pq.push(mp(key[v],v));
                parent[v] = u;
            }
        }
    }
    long long mst=0;
    // print edges of MST using parent array
    bool y=0;
    for (int i=1;i<=n;i++){
        //cout << i << " => " << parent[i] << " => " << key[i] << "\n";
        if ((i==u1&&parent[i]==v1)||(i==v1&&parent[i]==u1)) y=1;
        mst+=key[i];
    }
    if (y) return extraCheck(a,mst);
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    vector<pll> a[n+2];
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        if (i==1) {
            u1=u;
            v1=v;
        } else {
            a[u].pb(mp(v,w));
            a[v].pb(mp(u,w));
        }
    }
    int l=0,h=1234567890,ans=-1;
    while (l<=h) {
        int mid=(l+h)/2;
        //cout << mid << endl;
        if (minSpanningTree(a,mid)) {
            ans=mid;
            l=mid+1;
        } else h=mid-1;
    }
    cout << ans+1 << endl;
    return 0;
}
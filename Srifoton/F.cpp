/*
* some notes on centroid, a tree could have a maximum of two centroid and it will divide the tree into an equal size n / 2 (tree with odd vertices only have one centroid)
* centroids will store these centroid
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, siz[N], ans[N];
vector<int> adj[N], tep;
vector<int> centroids;

void dfs(int v, int par){
    siz[v] = 1;
    bool is_cen = true;
    for(auto x : adj[v]){
        if(x != par){
            dfs(x, v);
            siz[v] += siz[x];
            if(siz[x] > n / 2) is_cen = false;
        }
    }
    if(n - siz[v] > n / 2) is_cen = false;
    if(is_cen) centroids.push_back(v);
}

void dfs2(int v, int p){
    tep.push_back(v);
    for(auto x : adj[v]){
        if(x != p){
            dfs2(x, v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,int>> edges;
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (i == n/2+1) b = 1;
        edges.push_back({a, b});
    }
    dfs(1, -1);
    int cen = centroids[0];
    if(centroids.size() == 2){
        cen = centroids[1];
    }
    dfs2(cen, -1);
    long long res = 0;
    for(int i = 0; i < n; i++){
        ans[tep[i]] = tep[(i + n / 2) % n];
        res += (long long) abs(tep[i] - tep[(i + n / 2) % n]);
    }
    if (n & 1) {
        cout << res << endl;
        for (int i=0;i<n-1;i++) {
            cout << edges[i].second << " ";
        }
        cout << n-1 << endl;
    } else {
        cout << res << '\n';
        for(int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
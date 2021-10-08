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

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};


int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int virus[n+m+5];
    memset (virus,-1,sizeof(virus));
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        virus[x] = 0;
    }
    for (int i=1;i<=m;i++) {
        int x;
        cin >> x;
        virus[x] = 1;
    }

    vector<Edge> edges;
    for (int i=0;i<k;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        edges.pb({x,y,w});
    }

    // good

    vector<Edge> good;
    for (int i=0;i<edges.size();i++) {
        if (virus[edges[i].u] == virus[edges[i].v] && virus[edges[i].u] == 1) {
            good.pb(edges[i]);
        }
    }

    int cost = 0;
    vector<int> tree_id(n+m);
    for (int i = 0; i < n+m; i++)
        tree_id[i] = i;

    sort(good.begin(), good.end());

    for (Edge e : good) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n+m; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }

    // bad

    vector<Edge> bad;
    for (int i=0;i<edges.size();i++) {
        if (virus[edges[i].u] == virus[edges[i].v] && virus[edges[i].u] == 0) {
            bad.pb(edges[i]);
        }
    }

    int cost2 = 0;
    vector<int> tree_id2(n+m);
    for (int i = 0; i < n+m; i++)
        tree_id2[i] = i;

    sort(bad.begin(), bad.end());

    for (Edge e : bad) {
        if (tree_id2[e.u] != tree_id2[e.v]) {
            cost += e.weight;

            int old_id = tree_id2[e.u], new_id = tree_id2[e.v];
            for (int i = 0; i < n+m; i++) {
                if (tree_id2[i] == old_id)
                    tree_id2[i] = new_id;
            }
        }
    }
    cout << cost + cost2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
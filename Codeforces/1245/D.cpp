#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

struct E{
    LL u,v,w;
};

const LL N = 2005;
LL T,n,m,a,b,c;
E temp;
vector<E> graph; // Store the inputted graph (u, v, w).
vector<E> selected_edges; // Store the edges which is selected for the MST from given graph.
LL parent[N+2];

bool cstm(E a, E b){
    return a.w < b.w;
}

LL findParent(LL r){
    if(r == parent[r])return r;
    return parent[r] = findParent(parent[r]);
}

LL Kruskal_MST(){

    for(LL i=0;i<=n;i++)parent[i] = i;

    sort(graph.begin(),graph.end(),cstm);

    /*for(LL i=0;i<graph.size();i++){
        cout << graph[i].w << "\n";
    }*/

    LL edgeCounter = 0, totalCost = 0;

    LL len = graph.size();

    for(LL i=0; i<len;i++){

        LL parent_of_u = findParent(graph[i].u);
        LL parent_of_v = findParent(graph[i].v);

        if(parent_of_u != parent_of_v){
            parent[parent_of_u] = parent_of_v;
            totalCost += graph[i].w;
            selected_edges.pb(graph[i]);

            edgeCounter++;
            if(edgeCounter == n)
                break;
        }

    }
    return totalCost;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    pii loc[n+5];
    for (LL i=1;i<=n;i++) cin >> loc[i].fi >> loc[i].se;
    LL c[n+5];
    LL k[n+5];
    for (LL i=1;i<=n;i++) cin >> c[i];
    for (LL i=1;i<=n;i++) cin >> k[i];
    for (LL i=1;i<=n;i++) {
        for (LL j=i+1;j<=n;j++) {
            graph.pb({i,j,(k[i]+k[j]) * (abs(loc[i].fi-loc[j].fi)+abs(loc[i].se-loc[j].se))});
        }
        graph.pb({0,i,c[i]});
    }
    LL tot = 0;
    for (LL i=1;i<=n;i++) tot += c[i];
    LL mst = Kruskal_MST();
    cout << mst << endl;
    vector<int> langsung;
    for (int i=0;i<selected_edges.size();i++) {
        if (selected_edges[i].u==0) langsung.pb(selected_edges[i].v);
    }
    cout << langsung.size() << endl;
    for (int i=0;i<langsung.size();i++) cout << langsung[i] << " ";
    cout << endl;
    cout << (int)selected_edges.size()-langsung.size() << endl;
    for (int i=0;i<(int)selected_edges.size();i++)  {
        if (selected_edges[i].u!=0) cout << selected_edges[i].u << " " << selected_edges[i].v << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
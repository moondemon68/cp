
// A C++ program to find articulation points in an undirected graph 
#include<bits/stdc++.h>
#define NIL -1 
using namespace std; 

vector<int> adjacent[200005];
vector<int> art;
int cnt[200005];
int n,m,a,b;

void carianak(int s, int e) {
    vector<int>::iterator u; 
    cnt[s] = 1;
    for (u = adjacent[s].begin(); u != adjacent[s].end(); u++) {
        if (*u == e || cnt[*u] > 0) continue;
        carianak(*u, s);
        cnt[s] += cnt[*u];
    }
}

bool vis[200005];

bool ada(int s, int t) {
    stack<int> st;
    st.push(s);
    vis[s] = 1;
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        for (int i=0;i<adjacent[cur].size();i++) {
            int next = adjacent[cur][i];
            if (!vis[next]) {
                vis[next] = 1;
                st.push(next);
            }
        }
    }
    return vis[t];
}

// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void APUtil(int v, bool visited[], int disc[], int low[],  
                int parent[], bool ap[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void AP();    // prints articulation points 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that find articulation points using DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
// ap[] --> Store articulation points 
void Graph::APUtil(int u, bool visited[], int disc[],  
                                      int low[], int parent[], bool ap[]) 
{ 
    // A static variable is used for simplicity, we can avoid use of static 
    // variable by passing a pointer. 
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, disc, low, parent, ap); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // u is an articulation point in following cases 
  
            // (1) u is root of DFS tree and has two or more chilren. 
            if (parent[u] == NIL && children > 1) 
               ap[u] = true; 
  
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u. 
            if (parent[u] != NIL && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 

// The function to do DFS traversal. It uses recursive function APUtil() 
void Graph::AP() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V]; // To store articulation points 
  
    // Initialize parent and visited, and ap(articulation point) arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, disc, low, parent, ap); 
  
    if (ap[a] && ap[b]) {
        set<int> p, q;
        carianak(a, 0);
        // for (int i=0;i<n;i++) cout << cnt[i] << " ";
        // cout << endl;
        for (int i=0;i<adjacent[a].size();i++) {
            if (p.find(adjacent[a][i]) != p.end()) continue;
            for (int j=0;j<n;j++) vis[j] = 0;
            vis[a] = 1;
            if (!ada(adjacent[a][i], b)) {
                for (int j=0;j<n;j++) if (vis[j]) p.insert(j);
            }
        }
        // cout << p.size()-1 << endl;
        for (int i=0;i<n;i++) cnt[i] = 0;
        carianak(b, 0);
        // for (int i=0;i<n;i++) cout << cnt[i] << " ";
        // cout << endl;
        for (int i=0;i<adjacent[b].size();i++) {
            if (q.find(adjacent[b][i]) != q.end()) continue;
            for (int j=0;j<n;j++) vis[j] = 0;
            vis[b] = 1;
            if (!ada(adjacent[b][i], a)) {
                for (int j=0;j<n;j++) if (vis[j]) q.insert(j);
            }
        }
        // cout << q.size()-1 << endl;
        cout << (long long)(p.size()-1) * (long long)(q.size()-1) << endl;
    } else {
        cout << 0 << endl;
    }
    // Now ap[] contains articulation points, print them 
    // for (int i = 0; i < V; i++) 
    //     if (ap[i] == true) 
    //         art.push_back(i+1);
} 
  
// Driver program to test above function 
int main() 
{ 
    // Create graphs given in above diagrams 
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> a >> b;
        for (int i=0;i<n;i++) {
            adjacent[i].clear();
            cnt[i] = 0;
        }
        a--;
        b--;
        Graph g(n);
        for (int i=1;i<=m;i++) {
            int x,y;
            cin >> x >> y;x--;y--;
            g.addEdge(x, y);
            adjacent[x].push_back(y);
            adjacent[y].push_back(x);
        }
        g.AP();
    }
    return 0; 
} 
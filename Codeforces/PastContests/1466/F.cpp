#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL fpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

vector<LL> parent, ranks;

void make_set(LL v) {
    parent[v] = v;
    ranks[v] = 0;
}

LL find_set(LL v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(LL a, LL b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

struct Edge {
    LL u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> edges;
vector<Edge> result;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL n,m;
    cin >> n >> m;

    LL cost = 0;
    parent.resize(m+5);
    ranks.resize(m+5);
    for (LL i=1;i<=m+1;i++) make_set(i);
    
    for (LL i=1;i<=n;i++) {
        LL k;
        cin >> k;
        if (k == 1) {
            LL x;
            cin >> x;
            edges.pb({x, m+1, i});
            edges.pb({m+1, x, i});
        } else {
            LL x, y;
            cin >> x >> y;
            edges.pb({x, y, i});
            edges.pb({y, x, i});
        }
    }

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    sort(result.begin(), result.end());
    cout << fpow(2, result.size()) << " " << result.size() << endl;
    for (Edge e : result) {
        cout << e.weight << " ";
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
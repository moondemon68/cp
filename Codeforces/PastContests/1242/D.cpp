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

const int MAXN = 100000;
int link[MAXN+5], sz[MAXN+5];

void init() {
    for (int i=1;i<=MAXN;i++) link[i] = i;
    for (int i=1;i<=MAXN;i++) sz[i] = 1;
}

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    init();
    set<int> s;
    for (int i=1;i<=n;i++) {
        map<int,int> cnt;
        for (auto next : adj[i]) {
            if (next < i) {
                cnt[find(next)]++;
            }
        }

        vector<int> tmp;
        for (auto x : s) {
            if (sz[find(x)] > cnt[find(x)]) {
                unite(find(x), i);
                tmp.pb(x);
            }
        }
        for (auto x : tmp) {
            s.erase(x);
        }
        s.insert(i);
    }

    cout << s.size()-1 << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
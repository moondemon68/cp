#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int n;
LL a[200005], p[200005], tree[1600005], lazy[1600005];

void push(int node, int tl, int tr) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node];
    if (tl != tr) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int tl, int tr, int l, int r, LL val) {
    push(node, tl, tr);
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        lazy[node] += val;
        push(node, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    update(2*node, tl, mid, l, r, val);
    update(2*node+1, mid+1, tr, l, r, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

LL getmin() {
    push(1, 1, 2*n+1);
    return tree[1];
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> p[i];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        update(1, 1, 2*n+1, p[i]*2, 2*n+1, a[i]);
    }
    LL ans = 1e18;
    for (int i=1;i<n;i++) {
        update(1, 1, 2*n+1, p[i]*2, 2*n+1, -a[i]);
        update(1, 1, 2*n+1, 1, p[i]*2, a[i]);
        cout << getmin() << "->";
        for (int j=1;j<=4*n+1;j++) cerr << tree[j] << " ";
        cerr << endl;
        ans = min(ans, getmin());
    }
    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<int> p[m+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        a[x]--;
        a[y]--;
        p[x].pb(i);
        p[y].pb(i);
    }
    queue<int> q;
    for (int i=1;i<=n;i++) {
        if (a[i] > 0) q.push(i);
    }
    while (!q.empty()) {
        
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
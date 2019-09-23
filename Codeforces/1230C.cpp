#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
    // if (n<=6) {
    //     cout << m << endl;
    //     return 0;
    // }
    bool adj[n+5][n+5];
    memset (adj,0,sizeof(adj));
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        if (x>y) swap(x,y);
        adj[x][y]=1;
    }
    int p[n+5];
    memset (p,0,sizeof(p));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (adj[i][j]) p[i]++;
        }
    }  
    for (int i=1;i<=n;i++) cout << p[i] << ' ';
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
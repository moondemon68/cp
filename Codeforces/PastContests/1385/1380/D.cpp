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
    int x,k,y;
    cin >> x >> k >> y;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int b[m+5];
    for (int i=1;i<=m;i++) cin >> b[i];
    b[m+1] = -1;
    bool e[n+5];
    memset (e,0,sizeof(e));
    int p = 1;
    for (int i=1;i<=n;i++) {
        if (a[i] == b[p]) {
            p++;
        } else {
            e[i] = 1;
        }
    }
    for (int i=1;i<=n;i++) cout << e[i] << " ";
    if (p != m+1) {
        cout << -1 << endl;
        return 0;
    }
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
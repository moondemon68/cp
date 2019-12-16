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
    int n,m,b;
    cin >> n >> m >> b;
    int a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cin >> a[i][j];
    } 
    int ans=INT_MAX;
    for (int i=1;i<(1<<n);i++) {
        int x=i;
        vector<int> p;
        while(p.size()<n) {
            p.pb(x%2);
            x/=2;
        }
        vector<int> q;
        for (int j=0;j<n;j++) if (p[j]) q.pb(j+1);
        bool y=1;
        for (int j=0;j<q.size();j++) {
            for (int k=j+1;k<q.size();k++) {
                int cnt = 0;
                for (int l=1;l<=m;l++) {
                    cnt += abs(a[q[j]][l]-a[q[k]][l]);
                }
                if (cnt<=1) y=0;
            }
        }
        if (y) ans=min(ans, n-(int)q.size());
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
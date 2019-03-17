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
    int n;
    cin >> n;
    vector<int> adj[n+5];
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        for (int j=1;j<=x;j++) {
            int p;
            cin >> p;
            adj[i].pb(p);
        }
    }   
    int l=-1,r=INT_MAX;
    for (int i=1;i<=n;i++) {
        int maxl=-1;
        for (int j=0;j<(int)adj[i].size();j++) {
            int x=adj[i][j];
            if (j==(int)adj[i].size()-1) r=min(r,x);
            else maxl=max(maxl,x);
        }
        maxl++;
        l=max(l,maxl);
    }
    if (l<=r) cout << r << endl;
    else cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
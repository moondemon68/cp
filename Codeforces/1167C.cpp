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
    int a[n+5];
    for (int i=1;i<=n;i++) a[i]=-1;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int k;
        cin >> k;
        int b[k+5];
        for (int j=1;j<=k;j++) {
            cin >> b[j];
        }
        if (k==0||k==1) continue;
        for (int j=2;j<=k;j++) {
            adj[b[1]].pb(b[j]);
            adj[b[j]].pb(b[1]);
        }
    }

    for (int i=1;i<=n;i++) {
        if (a[i]!=-1) continue;
        a[i]=0;
        int cnt=1;
        vector<int> p;
        p.pb(i);
        stack<int> s;
        s.push(i);
        while (!s.empty()) {
            int cur=s.top();
            s.pop();
            for (int j=0;j<adj[cur].size();j++) {
                int next=adj[cur][j];
                if (a[next]==-1) {
                    cnt++;
                    a[next]=0;
                    p.pb(next);
                    s.push(next);
                }
            }
        }
        for (int j=0;j<p.size();j++) a[p[j]]=cnt;
    }
    for (int i=1;i<=n;i++) cout << a[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
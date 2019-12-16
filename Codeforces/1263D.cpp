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
    bool a[30][30];
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=0;j<s.size();j++) {
            for (int k=j;k<s.size();k++) {
                a[s[j]-'a'+1][s[k]-'a'+1] = 1;
            }
        }
    }
    vector<int> adj[30];
    for (int i=1;i<=26;i++) {
        for (int j=1;j<=26;j++) {
            if (a[i][j]) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    int cnt=0;
    bool vis[30];
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=26;i++) {
        if (!vis[i] && !adj[i].empty()) {
            cnt++;
            stack<int> s;
            s.push(i);
            vis[i]=1;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                for (int j=0;j<adj[cur].size();j++) {
                    int next= adj[cur][j];
                    if (!vis[next]) {
                        vis[next] = 1;
                        s.push(next);
                    }
                }
            }
        }
    }
    // for (int i=1;i<=26;i++) cout << vis[i] << " "; 
    // cout << endl;
    cout << cnt << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        if (s.size() == 1) {
            cout << "YES" << endl;
            cout << "abcdefghijklmnopqrstuvwxyz" << endl;
            continue;
        }
        bool a[30][30];
        memset (a,0,sizeof(a));
        for (int i=0;i<s.size()-1;i++) {
            a[s[i]-'a'][s[i+1]-'a'] = 1;
            a[s[i+1]-'a'][s[i]-'a'] = 1;
        }
        vector<int> adj[35];
        for (int i=0;i<26;i++) {
            for (int j=0;j<26;j++) {
                if (a[i][j]) {
                    adj[i].pb(j);
                }
            }
        }
        int satu = 0, dua = 0, start = 0;
        for (int i=0;i<26;i++) {
            if (adj[i].size() == 2) dua++;
            else if (adj[i].size() == 1) {
                satu++;
                start = i;
            }
        }
        if (satu != 2) {
            cout << "NO" << endl;
            continue;
        }
        queue<int> q;
        q.push(start);
        int vis[30];
        memset (vis,-1,sizeof(vis));
        vis[start] = 1;
        int par[30];
        memset (par,-1,sizeof(par));
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i=0;i<adj[cur].size();i++) {
                int next = adj[cur][i];
                if (vis[next] == -1) {
                    par[next] = cur;
                    vis[next] = vis[cur]+1;
                    q.push(next);
                }
            }
        }
        int maxi = 0, maxp = 0;
        for (int i=0;i<26;i++) {
            if (vis[i] > maxi) {
                maxi = vis[i];
                maxp = i;
            }
        }
        if (adj[maxp].size() != 1) {
            cout << "NO" << endl;
            continue;
        }
        int p[30];
        memset(p,-1,sizeof(p));
        int cnt = 0;
        bool y = 1;
        while (maxp != start) {
            p[cnt++] = maxp;
            maxp = par[maxp];
            if (maxp != start && adj[maxp].size() != 2) {
                y = 0;
                break;
            }
        }
        p[cnt++] = start;
        if (y) {
            cout << "YES" << endl;
            set<int> g;
            for (int i=0;i<26;i++) {
                if (p[i] != -1) g.insert(p[i]);
            }
            for (int i=0;i<26;i++) {
                if (p[i] == -1) {
                    for (int j=0;j<26;j++) {
                        if (g.find(j) == g.end()) {
                            p[i] = j;
                            g.insert(p[i]);
                            break;
                        }
                    }
                }
            }
            for (int i=0;i<26;i++) {
                cout << (char)(p[i]+'a');
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
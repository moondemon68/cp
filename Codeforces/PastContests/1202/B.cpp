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
    string s;
    cin >> s;
    int a[15][15];
    memset (a,0,sizeof(a));
    for (int i=0;i<s.size()-1;i++) {
        a[s[i]-'0'][s[i+1]-'0']++;
    }
    for (int x=0;x<=9;x++) {
        for (int y=0;y<=9;y++) {
            vector<int> adj[15];
            for (int i=0;i<=9;i++) {
                adj[i].pb((i+x)%10);
                adj[i].pb((i+y)%10);
            }
            int b[15][15];
            memset (b,-1,sizeof(b));
            for (int i=0;i<=9;i++) {
                int vis[15];
                memset (vis,-1,sizeof(vis));
                queue<int> q;
                q.push(adj[i][0]);
                q.push(adj[i][1]);
                vis[adj[i][0]] = 0;
                vis[adj[i][1]] = 0;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int i=0;i<adj[cur].size();i++) {
                        int next = adj[cur][i];
                        if (vis[next] == -1) {
                            vis[next] = vis[cur]+1;
                            q.push(next);
                        }
                    }
                }
                for (int j=0;j<=9;j++) {
                    b[i][j] = vis[j];
                }
            }

            // if (x == 1 && y == 1) {
            //     for (int i=0;i<=9;i++) {
            //         for (int j=0;j<=9;j++) {
            //             cout << b[i][j] << " ";
            //         }
            //         cout << endl;
            //     }
            // }

            int ans = 0;
            for (int i=0;i<=9;i++) {
                for (int j=0;j<=9;j++) {
                    if (a[i][j] > 0 && b[i][j] == -1) {
                        ans = -1;
                        break;
                    } else {
                        // if (x == 3 && y == 4 && a[i][j] != 0) cout << a[i][j] << " " << b[i][j] << endl;
                        ans += a[i][j] * b[i][j];
                    }
                }
                if (ans == -1) break;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
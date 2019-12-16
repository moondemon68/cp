#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int r,c;
        cin >> c >> r;
        char a[r+5][c+5];
        bool vis[r+5][c+5];
        memset (vis,0,sizeof(vis));
        int ans=0;
        pii start;
        for (int i=1;i<=r;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=c;j++) {
                a[i][j]=s[j-1];
                if (a[i][j]=='@') {
                    start=mp(i,j);
                    a[i][j]='.';
                }
            }
        }
        stack<pii> s;
        s.push(start);
        vis[start.fi][start.se]=1;
        while (!s.empty()) {
            ans++;
            pii cur = s.top();
            s.pop();
            for (int i=0;i<4;i++) {
                pii next = mp(cur.fi+dx[i], cur.se+dy[i]);
                if (next.fi>=1&&next.fi<=r&&next.se>=1&&next.se<=c&&a[next.fi][next.se]=='.'&&!vis[next.fi][next.se]) {
                    vis[next.fi][next.se]=1;
                    s.push(next);
                }
            }
        }
        cout << "Case " << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
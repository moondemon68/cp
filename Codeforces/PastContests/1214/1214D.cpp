#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int cnt[1000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    char a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    int ans=2;
    stack<pii> s;
    int vis[n+5][m+5];
    memset (vis,-1,sizeof(vis));
    s.push({n,m});
    vis[n][m]=1;
    int dx[]={-1,0};
    int dy[]={0,-1};
    while (!s.empty()) {
        pii cur=s.top();
        s.pop();
        for (int i=0;i<2;i++) {
            pii next={cur.fi+dx[i],cur.se+dy[i]};
            if (next.fi>=1&&next.fi<=n&&next.se>=1&&next.se<=m&&a[next.fi][next.se]=='.') {
                vis[next.fi][next.se]=vis[cur.fi][cur.se]+1;
                s.push(next);
            }
        }
    }
    int vis1[n+5][m+5];
    memset (vis1,-1,sizeof(vis1));
    s.push({1,1});
    vis1[1][1]=1;
    int dx1[]={1,0};
    int dy1[]={0,1};
    while (!s.empty()) {
        pii cur=s.top();
        s.pop();
        for (int i=0;i<2;i++) {
            pii next={cur.fi+dx1[i],cur.se+dy1[i]};
            if (next.fi>=1&&next.fi<=n&&next.se>=1&&next.se<=m&&a[next.fi][next.se]=='.') {
                vis1[next.fi][next.se]=vis1[cur.fi][cur.se]+1;
                s.push(next);
            }
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << vis[i][j] << " ";
    //         if (vis[i][j]!=-1) cout << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << vis1[i][j] << " ";
    //         if (vis[i][j]!=-1) cout << " ";
    //     }
    //     cout << endl;
    // }
    if (vis[1][1]==-1) ans=0;
    else {
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (a[i][j]=='.'&&vis[i][j]+vis1[i][j]==vis1[n][m]+1) cnt[vis[i][j]]++;
            }
        }
        for (int i=2;i<vis1[n][m];i++) {
            if (cnt[i]==1) {
                //cout << i << endl;
                ans=1;
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
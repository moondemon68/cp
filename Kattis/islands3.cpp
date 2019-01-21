#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
int r,c;
bool valid (int x,int y) {
    return x>=1&&x<=r&&y>=1&&y<=c;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    char a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j]=s[j-1];
        }
    }    
    bool vis[r+5][c+5];
    memset (vis,0,sizeof(vis));
    int ans=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (a[i][j]=='L'&&!vis[i][j]) {
                ans++;
                queue<pii> q;
                q.push(mp(i,j));
                vis[i][j]=1;
                while (!q.empty()) {
                    pii cur=q.front();
                    q.pop();
                    for (int m=0;m<=3;m++) {
                        pii next=mp(cur.fi+m[dx],cur.se+m[dy]);
                        if (valid(next.fi,next.se)&&!vis[next.fi][next.se]&&(a[next.fi][next.se]=='L'||a[next.fi][next.se]=='C')) {
                            vis[next.fi][next.se]=1;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

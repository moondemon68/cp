#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

char a[2005][2005];
bool vis[2005][2005];
int n,m,k;

bool valid(int i,int j) {
    return i>=1&&i<=n&&j>=1&&j<=m;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j]=s[j-1];
        }
    }
    int cnt=0;
    if (k==1) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if(a[i][j]=='.') cnt++;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    queue<pii> q;
    int mx[4]={1,0,-1,0};
    int my[4]={0,-1,0,1};
    int ans=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            vis[i][j]=(a[i][j]=='*');
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int cnt=0;
            if (!vis[i][j]&&a[i][j]=='.') {
                //cout << i << " " << j << endl;
                q.push(mp(i,j));
                vis[i][j]=1;
                while (!q.empty()) {
                    cnt++;
                    pii cur=q.front();
                    q.pop();
                    for (int k=0;k<4;k++) {
                        if (k%2==0) continue;
                        pii next=mp(cur.fi+mx[k],cur.se+my[k]);
                        if (valid(next.fi,next.se)&&!vis[next.fi][next.se]&&a[next.fi][next.se]=='.') {
                            vis[next.fi][next.se]=1;
                            q.push(next);
                        }
                    }
                }
            }
            //cout << cnt << endl;
            ans+=max(cnt-k+1,0);
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            vis[i][j]=(a[i][j]=='*');
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int cnt=0;
            if (!vis[i][j]&&a[i][j]=='.') {
                //cout << i << " " << j << endl;
                q.push(mp(i,j));
                vis[i][j]=1;
                while (!q.empty()) {
                    cnt++;
                    pii cur=q.front();
                    q.pop();
                    for (int k=0;k<4;k++) {
                        if (k%2==1) continue;
                        pii next=mp(cur.fi+mx[k],cur.se+my[k]);
                        if (valid(next.fi,next.se)&&!vis[next.fi][next.se]&&a[next.fi][next.se]=='.') {
                            vis[next.fi][next.se]=1;
                            q.push(next);
                        }
                    }
                }
            }
            //cout << cnt << endl;
            ans+=max(cnt-k+1,0);
        }
    }
    cout << ans << endl;
    return 0;
}
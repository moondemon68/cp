#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int countans(char a[255][255],int r,int c,int tryr,int tryc) {
    int vis[255][255];
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (a[i][j]=='1') vis[i][j]=1; else vis[i][j]=0;
        }
    }
    vis[tryr][tryc]=1;
    queue<pii> q;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (vis[i][j]==1) q.push(mp(i,j));
        }
    }
    while (!q.empty()) {
        pii cur=q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            pii next=mp(cur.fi+dx[i],cur.se+dy[i]);
            if (next.fi>=1&&next.fi<=r&&next.se>=1&&next.se<=c&&vis[next.fi][next.se]==0) {
                vis[next.fi][next.se]=vis[cur.fi][cur.se]+1;
                q.push(next);
            } 
        }
    }
    int ans=0;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            //cout << vis[i][j]<< " ";
            ans=max(ans,vis[i][j]);
        }
        //cout << endl;
    }
    return ans-1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int r,c;
        cin >> r >> c;
        char a[255][255];
        for (int i=1;i<=r;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=c;j++) {
                a[i][j]=s[j-1];
            }
        }
        int ans=123456789;
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                if (a[i][j]=='0') {
                    ans=min(ans,countans(a,r,c,i,j));
                }
            }
        }
        if (ans==123456789) ans=0;
        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
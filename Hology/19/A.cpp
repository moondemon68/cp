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
struct node{int x, y, rx, ry;};
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,x,y,r,c,ans=0;
    cin >> n >> m >> r >> c >> x >> y;
    deque<node> q;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j]=s[j-1];
        }
    }
    q.pb({r,c,x,y});
    while (!q.empty()) {
        node tmp = q.front();
        q.pop_front();
        int x = tmp.x, y= tmp.y;
        if (vis[x][y]) continue;
        vis[x][y]=1;
        ans++;
        if(x>1&&a[x-1][y]=='.') q.push_front({x-1,y,tmp.rx,tmp.ry});
        if(x<n&&a[x+1][y]=='.') q.push_front({x+1,y,tmp.rx,tmp.ry});
        if(y>1&&a[x][y-1]=='.'&&tmp.rx) q.push_back({x,y-1,tmp.rx-1,tmp.ry});
        if(y<m&&a[x][y+1]=='.'&&tmp.ry) q.push_back({x,y+1,tmp.rx,tmp.ry-1});
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
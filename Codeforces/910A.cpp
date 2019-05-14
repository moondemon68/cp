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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    vis[1]=0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int i=1;i<=k;i++) {
            int next=cur+i;
            if (next<=n&&vis[next]==-1&&s[next-1]=='1') {
                vis[next]=vis[cur]+1;
                q.push(next);
            }
        }
    }
    cout << vis[n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
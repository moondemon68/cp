#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<pii> e;
int test(vector<int> g) {
    int ans=0;
    bool done[10][10];
    memset(done,0,sizeof(done));
    for (int i=0;i<e.size();i++) {
        int x=e[i].fi,y=e[i].se;
        x=g[x-1];
        y=g[y-1];
        if (x>y) swap(x,y);
        x=min(6,x);
        y=min(6,y);
        if (!done[x][y]) {
            done[x][y]=1;
            ans++;
        }
    }
    return ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    if (n<=6) {
        cout << m << endl;
        return 0;
    }
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        e.pb(mp(x,y));
    }
    vector<int> g;
    for (int i=1;i<=7;i++) g.pb(i); 
    int ans=0;
    do {
        ans=max(ans,test(g));
    } while (next_permutation(g.begin(),g.end()));
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pii a,pii b) {
    if (a.se==b.se) return a.fi>b.fi;
    else return a.se>b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    pii p[n+5];
    for (int i=1;i<=n;i++) cin >> p[i].fi >> p[i].se;
    sort (p+1,p+n+1);
    reverse (p+1,p+n+1);
    priority_queue<pii> q;
    int t=0,ans=0;
    for (int i=1;i<=n;i++) {
        q.push(p[i]);
        bool y=0;
        while (!q.empty()&&!y) {
            if (q.top().fi+t<=m+1) {
                t++;
                ans+=q.top().se;
                q.pop();
                y=1;
            } else {
                q.pop();
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
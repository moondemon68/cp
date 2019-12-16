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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,s;
    cin >> n >> m >> s;
    vector<pii> a(n);
    for (int i=0;i<n;i++) cin >> a[i].fi >> a[i].se;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> b;
    for (int i=0;i<m;i++) {
        int x,y,z;
        b.push(mp(z,mp(x,y)));
    }
    sort (a.begin(),a.end());
    bool done[n+5],pake[m+5];
    memset (done,0,sizeof(done));
    memset (pake,0,sizeof(pake));
    for (int i=1;i<=n;i++) {
        if (done[i]) continue;
        
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
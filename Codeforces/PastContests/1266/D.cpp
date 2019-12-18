#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n, m;
    cin >> n >> m;
    LL a[n+5];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=m;i++) {
        LL x,y,z;
        cin >> x >> y >> z;
        a[x]+=z;
        a[y]-=z;
    }
    queue<LL> plus, minus;
    for (LL i=1;i<=n;i++) {
        if (a[i]>0) plus.push(i);
        else if (a[i]<0) minus.push(i);
    }
    vector<LL> ansx,ansy,ansz;
    while (!plus.empty()) {
        LL p = plus.front(), q = minus.front();
        plus.pop();
        minus.pop();
        LL z = min(a[p], a[q]*-1);
        a[p]-=z;
        a[q]+=z;
        ansx.pb(p); ansy.pb(q); ansz.pb(z);
        if (a[p] > 0) plus.push(p);
        if (a[q] < 0) minus.push(q);
    }
    cout << ansx.size() << endl;
    for (LL i=0;i<ansx.size();i++) cout << ansx[i] << " " << ansy[i] << " " << ansz[i] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
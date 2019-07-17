#include <bits/stdc++.h>
#define x first.first
#define y first.second
#define p second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pair<pii,LL> a,pair<pii,LL> b) {
    return a.x<b.x;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m,c;
    cin >> n >> m >> c;
    pair<pii,LL> a[m+5];
    for (LL i=1;i<=m;i++) cin >> a[i].x >> a[i].y >> a[i].p;
    sort (a+1,a+m+1,cmp);
    bool d[n+5];
    memset (d,0,sizeof(d));
    LL ans=0;
    LL cur=1;
    for (LL i=1;i<=m;i++) {
        if (a[i].x>cur) {
            ans+=c*(cur-a[i].x);
            cur=a[i].x;
        }
        //cout << cur << " " << ans << endl;
        if ((a[i].y-cur+1)*c>=a[i].p) {
            cur=a[i].y+1;
            ans+=a[i].p;
        }
    }
    if (cur<=n) ans+=(n-cur+1)*c;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
20 7 1
1 6 1
2 4 1
5 10 1
7 9 1
11 15 1
12 14 1
15 17 1
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool check(vector<pii> p,int x) {
    for (int i=0;i<p.size();i++) {
        if (p[i].fi!=x&&p[i].se!=x) return 0;
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int a[m+5],b[m+5];
    for (int i=1;i<=m;i++) cin >> a[i] >> b[i];
    int x;
    x=a[1];
    vector<pii> p;
    for (int i=1;i<=m;i++) {
        if (a[i]!=x&&b[i]!=x) p.pb(mp(a[i],b[i]));
    }
    if (p.size()==0||check(p,p[0].fi)||check(p,p[0].se)) {
        cout << "YES" << endl;
        return 0;
    }
    x=b[1];
    vector<pii> q;
    for (int i=1;i<=m;i++) {
        if (a[i]!=x&&b[i]!=x) q.pb(mp(a[i],b[i]));
    }
    if (q.size()==0||check(q,q[0].fi)||check(q,q[0].se)) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
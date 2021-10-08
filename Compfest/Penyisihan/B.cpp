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
    LL n,m;
    cin >> n >> m;
    pii a[n+5];
    memset(a,0,sizeof(a));
    map<LL,LL> gabung;
    for (LL i=1;i<=n;i++) cin >> a[i].fi;
    for (LL i=1;i<=n;i++) cin >> a[i].se;
    for (LL i=1;i<=n;i++) gabung[(a[i].fi % m)] += a[i].se;
    LL p = 1;
    for (auto x : gabung) {
        a[p] = {x.fi, x.se};
        p++;
    }
    p--;
    sort(a+1,a+p+1);
    reverse(a+1,a+p+1);

    // for (LL i=1;i<=p;i++) cout << a[i].fi << " ";
    // cout << endl;
    // for (LL i=1;i<=p;i++) cout << a[i].se << " ";
    // cout << endl;
    

    LL ans = 0;
    LL sum = 0;
    for (LL i=1;i<=p;i++) {
        sum += a[i].fi * a[i].se;
    }
    // cout << sum << endl;
    for (LL i=2;i<=p;i++) a[i].se += a[i-1].se;
    LL lastdiff = 0, muterpos = 0, muterneg = 0;
    for (LL i=1;i<=p;i++) {
        LL diff = m-1 - a[i].fi;
        LL d = diff - lastdiff; // difference antar step

        if (i == 1) {
            sum += a[p].se * d;
        } else if (i == 2) {
            sum += a[i-1].se * ((a[i-1].fi + diff) % m - (a[i-1].fi + lastdiff) % m);
            sum += (a[p].se - a[i-1].se) * d;
        } else {
            sum += a[i-2].se * d;
            sum += (a[i-1].se - a[i-2].se) * ((a[i-1].fi + diff) % m - (a[i-1].fi + lastdiff) % m);
            sum += (a[p].se - a[i-1].se) * d;
        }

        // cout << lastdiff << " " << diff << " " << d << " " << sum << endl;
        ans = max(ans, sum);
        lastdiff = diff;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
6 6
1 3 4 1 3 4
3 1 2 9 1 4
74

1 3
1 9
3 1
3 1
4 2
4 4

4 4 3 3 1 1 x
5 5 4 4 2 2 62
0 0 5 5 3 3 46 (-16)
1 1 0 0 4 4 x
2 2 1 1 5 5 74 (+32)
3 3 2 2 0 0 x

3 9 1 1 2 4 



6 6
5 4 3 2 1 0
2 3 4 5 6 1
62
*/
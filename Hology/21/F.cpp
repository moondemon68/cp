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

bool cmp(pii a, pii b) {
    return a.se > b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    pii a[n];
    for (LL i = 0; i < n; i++) {
        cin >> a[i].fi;
    }
    for (LL i = 0; i < n; i++) {
        cin >> a[i].se;
    }
    sort(a, a + n, cmp);
    LL ans = 0;
    for (LL i=0;i<n;i++) {
        ans += a[i].fi - i * a[i].se;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
4
7 5 3 2
3 2 2 1

4
2 3 5 7
1 2 2 3
*/
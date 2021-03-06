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
    int n;
    cin >> n;
    int a[n+5];
    int b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    pii p[n+5];
    for (int i=1;i<=n;i++) {
        p[a[i]].fi = i;
        p[b[i]].se = i;
    }
    // for (int i=1;i<=n;i++) cout << p[i].fi << " " << p[i].se << endl;
    int cnt[n+5];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        int x = p[i].fi-p[i].se;
        if (x < 0) x += n;
        cnt[x]++;
    }
    int ans = 0;
    for (int i=0;i<=n;i++) ans = max(ans, cnt[i]);
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
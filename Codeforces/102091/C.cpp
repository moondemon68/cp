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
    int n,w;
    cin >> n >> w;
    int ans=0;
    pii a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;
    for (int i=1;i<=n;i++) {
        int cnt = 1, cur = a[i].se, curi = a[i].fi;
        for (int j=i+1;j<=n;j++) {
            if (abs(a[j].se-cur) <= w && a[j].fi > curi) {
                cnt++;
                cur = a[j].se;
                curi = a[j].fi;
            }
        }
        ans=max(ans,cnt);
    }
    cout << ans-1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
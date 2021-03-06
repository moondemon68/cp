#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pii a,pii b) {
    if (a.se == b.se) return a.fi<b.fi;
    else return a.se<b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pii a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort (a+1,a+n+1,cmp);
    int cur=a[1].se,ans=1;
    for (int i=2;i<=n;i++) {
        if (a[i].fi>=cur) {
            ans++;
            cur=a[i].se;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
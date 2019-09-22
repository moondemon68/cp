#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
    pii a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort (a+1,a+n+1);
    reverse(a+1,a+n+1);
    int ans=0;
    vector<int> p;
    for (int i=1;i<=n;i++) {
        ans+=a[i].fi*(i-1)+1;
        p.pb(a[i].se);
    }
    cout << ans << endl;
    for (int i=0;i<p.size();i++) cout << p[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
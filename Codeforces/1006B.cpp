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
    int n,k;
    cin >> n >> k;
    pii a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi;
        a[i].se=i;
    }
    sort (a+1,a+n+1);
    reverse(a+1,a+n+1);
    int ans=0;
    vector<int> p;
    for (int i=1;i<=k;i++) ans+=a[i].fi;
    cout << ans << endl;
    for (int i=1;i<=k;i++) p.pb(a[i].se);
    p.pb(0);
    sort (p.begin(),p.end());
    for (int i=1;i<p.size()-1;i++) cout << p[i]-p[i-1] << " ";
    cout << n-p[p.size()-2];
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    vector<LL> p;
    LL x=1;
    for (int i=0;i<=18;i++) {
        p.pb(x);
        x*=10;
    }
    x=2;
    for (int i=0;i<18;i++) {
        p.pb(x);
        x*=10;
    }
    x=5;
    for (int i=0;i<18;i++) {
        p.pb(x);
        x*=10;
    }
    sort (p.begin(),p.end());
    reverse (p.begin(),p.end());
    LL n;
    cin >> n;
    LL ans=0;
    vector<pair<LL,LL>> a;
    for (int i=0;i<p.size();i++) {
        if (n>=p[i]) {
            ans++;
            a.pb(mp(p[i],n/p[i]));
            n%=p[i];
        }
    }
    cout << ans << endl;
    for (int i=0;i<a.size();i++) {
        cout << a[i].fi << " " << a[i].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
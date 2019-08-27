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
    vector<LL> p,m,z;
    for (int i=1;i<=n;i++) {
        LL x;cin >> x;
        if (x==0) z.pb(x);
        else if (x>0) p.pb(x);
        else if (x<0) m.pb(x);
    }
    LL ans=0;
    for (int i=0;i<p.size();i++) {
        ans+=p[i]-1;
    }
    for (int i=0;i<m.size();i++) {
        ans+=(m[i]*-1)-1;
    }
    if (m.size()%2==0) ans+=z.size();
    else {
        if (z.size()==0) {
            ans+=2;
        } else ans+=z.size();
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
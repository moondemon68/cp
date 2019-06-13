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
    LL n,k;
    cin >> n >> k;
    LL g[n+5];
    vector<pair<LL,int>> p;
    for (int i=1;i<=n;i++) {
        LL a;
        cin >> a;
        g[i]=a;
        p.pb(mp(a,i));
    }
    sort (p.begin(),p.end());
    LL ans=0,x=p[n/2].fi,ansid=0;
    for (int i=1;i<=n;i++) {
        if (g[i]==x) {
            ansid=i;
            break;
        }
    }
    for (int i=0;i<p.size();i++) {
        ans+=abs(p[i].fi-x);
    }
    if (ans>=k) cout << ansid << " " << ans-k;
    else {
        LL lebih=k-ans;
        cout << 1 << " ";
        if (lebih%2==0) cout << 0; else cout << 1;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
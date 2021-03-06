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
    LL s,b;
    cin >> s >> b;
    LL a[s+5];
    for (LL i=1;i<=s;i++) cin >> a[i];
    vector<pii> p;
    for (LL i=1;i<=b;i++) {
        LL x,y;
        cin >> x >> y;
        p.pb(mp(x,y));
    }
    sort (p.begin(),p.end());
    p.pb(mp(1234567890,0));
    for (LL i=1;i<p.size();i++) {
        p[i].se+=p[i-1].se;
        //cout << p[i].fi;
    }
    for (LL i=1;i<=s;i++) {
        LL x=a[i];
        //cout << x << " ";
        LL l=0,h=p.size(),ans=-1;
        while (l<=h) {
            LL m=(l+h)/2;
            if (p[m].fi>x) {
                h=m-1;
            } else {
                ans=m;
                l=m+1;
            }
        }
        if (ans==-1) cout << "0 "; else cout << p[ans].se << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
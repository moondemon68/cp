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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    LL c[n+5];
    LL a[n+5];
    memset (a,0,sizeof(a));
    memset (c,0,sizeof(c));
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> c[i];
    priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> cheap;
    for (int i=1;i<=n;i++) cheap.push(mp(c[i],i));
    //while (!cheap.empty()) {
    //    cout << cheap.top().fi << cheap.top().se << endl;
    //    cheap.pop();
    //}
    for (int i=1;i<=m;i++) {
        int t;
        LL d;
        cin >> t >> d;
        LL ans=0;
        if (a[t]>=d) {
            ans+=c[t]*d;
            a[t]-=d;
            d=0;
        } else {
            ans+=c[t]*a[t];
            d-=a[t];
            a[t]=0;
            while (!cheap.empty()&&d>0) {
                if (cheap.empty()) {
                    ans=0;
                    break;
                } else {
                    LL stock=a[cheap.top().se];
                    if (stock==0) {
                        cheap.pop();
                    } else if (stock>=d) {
                        ans+=cheap.top().fi*d;
                        a[cheap.top().se]-=d;
                        d=0;
                    } else {
                        ans+=cheap.top().fi*stock;
                        d-=stock;
                        a[cheap.top().se]=0;
                    }
                }
            }
        }
        if (d!=0) ans=0;
        cout << ans << endl;
        //for (int i=1;i<=n;i++) cout << a[i] << " ";
        //cout << endl;
    }
    return 0;
}
//Mencari Banyaknya Kemungkinan ABCDEF
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
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<LL> abc,def;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                abc.pb(a[i]*a[j]+a[k]);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                def.pb((a[i]+a[j])*a[k]);
            }
        }
    }
    LL ans=0;
    sort (abc.begin(),abc.end());
    sort (def.begin(),def.end());
    for (int i=0;i<abc.size();i++) {
        auto l=lower_bound(def.begin(),def.end(),abc[i]);
        auto r=upper_bound(def.begin(),def.end(),abc[i]);
        LL p=r-l;
        ans+=p;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
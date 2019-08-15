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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        LL a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        LL x=0;
        map<LL,vector<LL>> m;
        m[0].pb(-1);
        for (int i=1;i<=n;i++) {
            x^=a[i];
            m[x].pb(i-1);
        }
        LL ans=0;
        for (auto i=m.begin();i!=m.end();i++) {
            vector<LL> v=i->second;
            LL p=v.size();
            LL q=(-1)*(p-1);
            for (LL j=0;j<v.size();j++) {
                ans+=q*v[j];
                q+=2;
            }
            ans-=p*(p-1)/2;
            //cout << ans << endl;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
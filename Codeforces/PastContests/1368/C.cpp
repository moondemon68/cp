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
    int n;
    cin >> n;
    vector<pii> v;
    v.pb({0,0});
    v.pb({0,1});
    for (int i=1;i<=n;i++) {
        v.pb({i,i-1});
        v.pb({i,i});
        v.pb({i,i+1});
    }
    v.pb({n+1,n+1});
    v.pb({n+1,n});
    cout << v.size() << endl;
    for (auto x : v) cout << x.fi << " " << x.se << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    if (n%2==1) {
        cout << "NO" << endl;
        return 0;
    }
    pii a[n+5];
    for (int i=0;i<n;i++) cin >> a[i].fi >> a[i].se;
    bool y = 1;
    set<pii> s;
    for (int i=0;i<n/2;i++) {
        s.insert({a[i].fi+a[i+n/2].fi, a[i].se+a[i+n/2].se});
    }
    if (s.size() == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
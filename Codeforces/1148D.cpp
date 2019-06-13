#include <bits/stdc++.h>
#define fi first.first
#define se first.second
#define id second
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
    pair<pii,int> a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].id=i;
    }
    vector<pair<pii,int>> b,c;
    for (int i=1;i<=n;i++) {
        if (a[i].fi<a[i].se) b.pb(a[i]); else c.pb(a[i]);
    }
    sort (b.begin(),b.end());
    sort (c.begin(),c.end());
    if (b.size()>=c.size()) {
        cout << b.size() << endl;
        for (int i=b.size()-1;i>=0;i--) cout << b[i].id << " ";
    } else {
        cout << c.size() << endl;
        for (int i=0;i<c.size();i++) {
            cout << c[i].id << " ";
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
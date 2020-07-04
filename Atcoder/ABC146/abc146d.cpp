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
    pii a[n+5];
    for (int i=1;i<n;i++) cin >> a[i].fi >> a[i].se;
    int c[n+5];
    memset (c,0,sizeof(c));
    vector<int> v[n+5];
    for (int i=1;i<n;i++) {
        v[a[i].fi].pb(i);
        v[a[i].se].pb(i);
    }
    for (int i=1;i<=n;i++) {
        int p = 1;
        set<int> udah;
        vector<int> belum;
        for (int j=0;j<v[i].size();j++) {
            int x = v[i][j];
            if (c[x] != 0) {
                udah.insert(c[x]);
            } else {
                belum.pb(x);
            }
        }
        for (int j=0;j<belum.size();j++) {
            while (udah.find(p) != udah.end()) {
                p++;
            }
            c[belum[j]] = p;
            udah.insert(p);
            p++;
        }
    }
    int maxi=0;
    for (int i=1;i<n;i++) maxi = max(maxi, c[i]);
    cout << maxi << endl;
    for (int i=1;i<n;i++) cout << c[i] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
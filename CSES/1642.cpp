#include <bits/stdc++.h>
#define num first
#define fi second.first
#define se second.second
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
    int n,x;
    cin >> n >> x;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector< pair<int,pii> > v;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            v.pb(mp(a[i]+a[j],mp(i,j)));
        }
    }
    sort (v.begin(),v.end());
    int l=0,h=v.size()-1;
    while (l<h) {
        if (v[l].num+v[h].num == x) {
            set<int> s;
            s.insert(v[l].fi);
            s.insert(v[l].se);
            s.insert(v[h].fi);
            s.insert(v[h].se);
            if (s.size() == 4) {
                cout << v[l].fi << " " << v[l].se << " " << v[h].fi << " " << v[h].se << endl;
                return 0;
            } else {
                l++;
            }
        } else if (v[l].num+v[h].num < x) {
            l++;
        } else {
            h--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
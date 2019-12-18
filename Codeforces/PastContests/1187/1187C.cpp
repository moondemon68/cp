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
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) a[i]=n;
    vector<pii> v;
    int c=n;
    for (int i=1;i<=m;i++) {
        int x,l,r;
        cin >> x >> l >> r;
        if (x==0) {
            for (int j=l;j<=n;j++) {
                a[j]=c;
                c--;
                if (j==n) {
                    a[j]++;
                    c++;
                }
            }
        } else {
            v.pb(mp(l,r));
        }
    }
    bool y=1;
    for (int i=0;i<v.size();i++) {
        for (int j=v[i].fi+1;j<=v[i].se;j++) {
            if (a[j]<a[j-1]) y=0;
        }
    }
    if (y) {
        cout << "YES" << endl;
        for (int i=1;i<=n;i++) cout << a[i] << " ";
    }
    else {
        cout << "NO" << endl;
        //for (int i=1;i<=n;i++) cout << a[i] << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
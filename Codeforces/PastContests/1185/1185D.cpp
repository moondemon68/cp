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

bool test(vector<int> p) {
    int d=p[1]-p[0];
    for (int i=0;i<p.size()-1;i++) {
        if (p[i+1]-p[i]!=d) {
            return 0;
        }
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n==2) {
        cout << 1 << endl;
        return 0;
    }
    pii a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi;
        a[i].se=i;
    }
    sort (a+1,a+n+1);
    int d=a[2].fi-a[1].fi,ans=-1,ans2=-1;
    for (int i=1;i<n;i++) {
        if (a[i+1].fi-a[i].fi!=d) {
            ans=a[i+1].se; 
            ans2=a[i].se;
            break;
        }
    }
    if (ans==-1) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> p;
    for (int i=1;i<=n;i++) {
        if (a[i].se==ans) continue;
        else p.pb(a[i].fi);
    }
    if (test(p)) {
        cout << ans << endl;
        return 0;
    }
    vector<int> s;
    for (int i=1;i<=n;i++) {
        if (a[i].se==ans2) continue;
        else s.pb(a[i].fi);
    }
    if (test(s)) {
        cout << ans2 << endl;
        return 0;
    }
    vector<int> q;
    for (int i=2;i<=n;i++) {
        q.pb(a[i].fi);
    }
    if (test(q)) {
        cout << a[1].se << endl;
        return 0;
    }
    vector<int> r;
    for (int i=1;i<n;i++) {
        r.pb(a[i].fi);
    }
    if (test(r)) {
        cout << a[n].se << endl;
        return 0;
    }
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
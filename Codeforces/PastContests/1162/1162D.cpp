#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool check(vector<pii> a,vector<pii> b) {
    for (int i=0;i<a.size();i++) {
        if (b[i].fi>b[i].se) swap(b[i].fi,b[i].se);
    }
    sort (b.begin(),b.end());
    for (int i=0;i<a.size();i++) {
        if (a[i]!=b[i]) return 0;
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<pii> ori;
    for (int i=1;i<=m;i++) {
        pii a;
        cin >> a.fi >> a.se;
        ori.pb(mp(a.fi,a.se));
    }
    for (int i=0;i<ori.size();i++) {
        if (ori[i].fi>ori[i].se) swap(ori[i].fi,ori[i].se);
    }
    sort (ori.begin(),ori.end());
    vector<int> div;
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            div.pb(i);
            div.pb(n/i);
        }
    }
    for (auto i:div) {
        if (i==n) continue;
        vector<pii> a;
        for (int j=0;j<m;j++) {
            a.pb(mp((ori[j].fi+i-1)%n+1,(ori[j].se+i-1)%n+1));
        }
        if (check(ori,a)) {
            //cout << i << endl;
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
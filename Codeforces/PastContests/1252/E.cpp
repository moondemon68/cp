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
    int n,l,r,k;
    cin >> n >> l >> r >> k;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    pii b[n+5];
    b[n] = {l,r};
    for (int i=n-1;i>=1;i--) {
        if (a[i] == a[i+1]) b[i] = b[i+1];
        else if (a[i] > a[i+1]) b[i] = {b[i+1].fi+1, min(b[i+1].se+k, r)};
        else b[i] = {max(l, b[i+1].fi-k), b[i+1].se-1};
        if (b[i].fi > r || b[i].se < l) {
            cout << -1 << endl;
            return 0;
        }
    }
    // for (int i=1;i<=n;i++) {
    //     cout << b[i].fi << ":" << b[i].se << " ";
    // }
    // cout << endl;
    int cur = b[1].fi;
    cout << b[1].fi << " ";
    for (int i=2;i<=n;i++) {
        if (a[i] == a[i-1]) cur = cur;
        else if (a[i] > a[i-1]) {
            pii current = {cur+1, min(cur+k, r)};
            if (current.fi >= b[i].fi && current.fi <= b[i].se) cur = current.fi;
            else if (b[i].fi >= current.fi && b[i].fi <= current.se) cur = b[i].fi;
        } else {
            pii current = {max(cur-k, l), cur-1};
            if (current.fi >= b[i].fi && current.fi <= b[i].se) cur = current.fi;
            else if (b[i].fi >= current.fi && b[i].fi <= current.se) cur = b[i].fi;
        }
        cout << cur << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
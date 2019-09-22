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
    int n,x;
    cin >> n >> x;
    pii a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort (a+1,a+n+1);
    int l=1,h=n;
    while (l<h) {
        if (a[l].fi+a[h].fi == x) {
            cout << a[l].se << " " << a[h].se << endl;
            return 0;
        } else if (a[l].fi + a[h].fi < x) {
            l++;
        } else {
            h--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
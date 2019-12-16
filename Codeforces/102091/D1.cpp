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
    int n,k;
    cin >> n >> k;
    pii a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi;
    for (int i=1;i<=n;i++) cin >> a[i].se;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) {
        if (k>=a[i].fi) {
            k+=a[i].se;
        }
    }
    cout << k << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
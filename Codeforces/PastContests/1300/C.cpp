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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans = 1;
    for (int i=30;i>=0;i--) {
        vector<int> v;
        for (int j=1;j<=n;j++) {
            if ((a[j] & (1 << i))) v.pb(j);
        }
        if (v.size() == 1) {
            ans = v[0];
            break;
        }
    }
    cout << a[ans] << " ";
    for (int i=1;i<=n;i++) {
        if (i != ans) cout << a[i] << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
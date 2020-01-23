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
    int q,x;
    cin >> q >> x;
    int ans = 0;
    int a[x+5];
    memset (a,0,sizeof(a));
    while (q--) {
        int k;
        cin >> k;
        if (k % x == ans % x) {
            ans++;
        } else {
            a[k%x]++;
        }
        while (a[ans%x] > 0) {
            a[ans%x]--;
            ans++;
        }
        // cout << "*";
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n;
    cin >> n;
    int a[n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans = 0;
    bool belum[n+5];
    memset (belum,1,sizeof(belum));
    for (int i=1;i<=n;i++) {
        if (a[i] == 0) {
            if (a[i+1] > 0) {
                ans++;
                a[i+1]--;
            } else if (a[i-1] > 0 && belum[i]) {
                ans++;
                a[i-1]--;
            }
        } else if (a[i] > 0) {
            ans++;
            a[i]--;
        }
        if (a[i] > 0) {
            if (a[i+1] == 0 && i != n) {
                belum[i+1] = 0;
                ans++;
                a[i]--;
            }
        }
    }
    // for (int i=1;i<=n;i++) cerr << a[i] << " ";
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
3
3 0 0
2
*/
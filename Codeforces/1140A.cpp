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
    cin >>n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans=0;
    bool r[n+5];
    memset (r,0,sizeof(r));
    for (int i=1;i<=n;i++) {
        int y=1;
        for (int j=1;j<=i;j++) {
            if (a[j]>i) {
                y=0;
                break;
            }
        }
        if (y) ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n,z;
    cin >> n >> z;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    bool d[n+5];
    memset (d,0,sizeof(d));
    int ans=0,l=1,r=n/2;
    while (l<=r) {
        int m=(l+r)/2;
        bool y=1;
        for (int i=1;i<=m;i++) {
            if (a[n-m+i]-a[i]<z) {
                y=0;
                break;
            }
        }
        if (y) {
            ans=m;
            l=m+1;
        } else {
            r=m-1;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
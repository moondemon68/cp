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
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        a[i]=abs(a[i]);
    }
    sort (a+1,a+n+1);
    LL ans=0;
    for (int i=1;i<=n;i++) {
        int l=i,r=n,p=i;
        while (l<=r) {
            int m=(l+r)/2;
            if (a[m]<=2*a[i]) {
                p=m;
                l=m+1;
            } else {
                r=m-1;
            }
        }
        ans+=(LL)(p-i);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
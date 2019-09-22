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
    int n,m,k;
    cin >> n >> m >> k;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int b[m+5];
    for (int i=1;i<=m;i++) cin >> b[i];
    sort (a+1,a+n+1);
    sort (b+1,b+m+1);
    int pa=1,pb=1,ans=0;
    while (pa<=n&&pb<=m) {
        if (a[pa]>=b[pb]-k && a[pa]<=b[pb]+k) {
            pa++;
            pb++;
            ans++;
        } else if (a[pa]<b[pb]-k) {
            pa++;
        } else {
            pb++;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
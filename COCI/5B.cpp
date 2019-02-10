#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

    int x[2000005];
int main () {
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    memset (x,0,sizeof(x));
    for (int i=1;i<=n;i++) {
        if (b[i]-a[i]>=0) x[b[i]-a[i]]++;
    }
    int ans=0;
    for (int i=0;i<=2000000;i++) ans=max(ans,x[i]);
    cout << ans << endl;
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
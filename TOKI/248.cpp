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
    int n,m;
    cin >> n >> m;
    int a[n+5],b[m+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++) cin >> b[i];
    sort (a+1,a+n+1);
    sort (b+1,b+m+1);
    int ans=0,l=1,r=1;
    while (l<=n&&r<=m) {
        if (a[l]==b[r]||a[l]+1==b[r])  {
            ans++;
            l++;
            r++;
        } else if (a[l]<b[r]) l++;
        else r++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
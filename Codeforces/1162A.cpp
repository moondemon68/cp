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
    int n,h,m;
    cin >> n >> h >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) a[i]=h;
    for (int i=1;i<=m;i++) {
        int l,r,x;
        cin >> l >> r >> x;
        for (int j=l;j<=r;j++) {
            a[j]=min(a[j],x);
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        //cout << a[i] << " ";
        ans+=a[i]*a[i];
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
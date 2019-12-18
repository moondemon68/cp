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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        a[i]=a[i-1]+(s[i-1]=='a');
        //cout << a[i];
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        int l=i,r=n,p=i;
        while (l<=r) {
            int m=(l+r)/2;
            int x=a[m]-a[i-1],y=m-(i-1);
            if (y-x<=k) {
                p=m;
                l=m+1;
            } else r=m-1;
        }
        ans=max(ans,p-i+1);
    }
    int b[n+5];
    memset (b,0,sizeof(b));
    for (int i=1;i<=n;i++) {
        b[i]=b[i-1]+(s[i-1]=='b');
    }
    for (int i=1;i<=n;i++) {
        int l=i,r=n,p=i;
        while (l<=r) {
            int m=(l+r)/2;
            int x=b[m]-b[i-1],y=m-(i-1);
            if (y-x<=k) {
                p=m;
                l=m+1;
            } else r=m-1;
        }
        ans=max(ans,p-i+1);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    LL n,q;
    cin >> n >> q;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL tot=0;
    a[0]=0;
    for (LL i=1;i<=n;i++) {
        tot+=a[i];
        a[i]+=a[i-1];
    }
    for (LL i=1;i<=n;i++) a[i]=tot-a[i];
    a[0]=tot;
    //for (int i=0;i<n;i++) cout << a[i] << " ";
    //cout << endl;
    LL cur=tot;
    while (q--) {
        LL x;
        cin >> x;
        cur-=x; 
        if (cur<=0) cur=tot;
        //cout << cur << " ";
        LL l=0,r=n-1,ans=0;
        while (l<=r) {
            LL m=(l+r)/2;
            if (a[m]>=cur) {
                ans=m;
                l=m+1;
            } else {
                r=m-1;
            }
        }
        cout << n-ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
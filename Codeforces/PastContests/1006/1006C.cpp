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
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    if (n==1) {
        cout << 0 << endl;
        return 0;
    } else if (n==2) {
        if (a[1]==a[2]) cout << a[1]; else cout << 0;
        cout << endl;
        return 0;
    }
    LL ans=0;
    LL l=1,r=n,suml=a[1],sumr=a[n];
    while (l<r) {
        if (suml==sumr) {
            ans=suml;
            l++;
            suml+=a[l];
        } else if (suml>sumr) {
            r--;
            sumr+=a[r];
        } else {
            l++;
            suml+=a[l];
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    //cout << endl;
    int oddp[n+5],evenp[n+5];
    memset (evenp,0,sizeof(evenp));
    memset (oddp,0,sizeof(oddp));
    for (int i=2;i<=n;i+=2) {
        evenp[i]=evenp[i-2]+a[i];
        
    }
    for (int i=1;i<=n;i++) {
        if (evenp[i]==0) evenp[i]=evenp[i-1];
        //cout << evenp[i] << " ";
    }
    //cout << endl;
    oddp[1]=a[1];
    for (int i=3;i<=n;i+=2) {
        oddp[i]=oddp[i-2]+a[i];
        
    }
    for (int i=1;i<=n;i++) {
        if (oddp[i]==0) oddp[i]=oddp[i-1];
        //cout << oddp[i] << " ";
    }
    int ans=0;
    //cout << endl;
    for (int i=1;i<=n;i++) {
        int odd=0,even=0;
        if (i%2==1) {
            odd+=oddp[i-1]-oddp[0];
            even+=evenp[i-1]-evenp[0];
            odd+=evenp[n]-evenp[i];
            even+=oddp[n]-oddp[i];
        } else {
            odd+=oddp[i-1]-oddp[0];
            even+=evenp[i-1]-evenp[0];
            odd+=evenp[n]-evenp[i];
            even+=oddp[n]-oddp[i];
        }
        if (odd==even) ans++;
    }
    cout << ans << endl;
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
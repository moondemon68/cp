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
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans=0;
    for (int i=1;i<n;i++) {
        if (a[i]==1&&a[i+1]==2) ans+=3;
        if (a[i]==1&&a[i+1]==3) ans+=4;
        if (a[i]==2&&a[i+1]==1) ans+=3;
        if (a[i]==2&&a[i+1]==3) ans-=9999999;
        if (a[i]==3&&a[i+1]==1) ans+=4;
        if (a[i]==3&&a[i+1]==2) ans-=9999999;
    }
    for (int i=1;i<=n-2;i++) {
        if (a[i]==3&&a[i+1]==1&&a[i+2]==2) ans--;
    }
    if (ans<0) {
        cout << "Infinite" << endl;
    } else {
        cout << "Finite" << endl;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
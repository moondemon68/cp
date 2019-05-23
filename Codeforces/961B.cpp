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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    bool wake[n+5];
    for (int i=1;i<=n;i++) cin >> wake[i];
    int total[n+5],melek[n+5];
    total[0]=0; melek[0]=0;
    for (int i=1;i<=n;i++) {
        total[i]=a[i]+total[i-1];
        if (wake[i]) melek[i]=a[i]+melek[i-1]; else melek[i]=melek[i-1];
    }
    int ans=0;
    //for (int i=1;i<=n;i++) {
    //    cout << total[i] << " " << melek[i] << endl;
    //}
    for (int i=1;i<=n-k+1;i++) {
        //cout << total[i+k-1]-total[i-1]-melek[i+k-1]+melek[i-1]+melek[n] << endl;
        ans=max(ans,total[i+k-1]-total[i-1]-melek[i+k-1]+melek[i-1]+melek[n]);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
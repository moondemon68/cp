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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int a[n+5];
        a[0]=0;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) a[i]^=a[i-1];
        int ans=0;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                for (int k=j;k<=n;k++) {
                    if (a[j-1]^a[i-1]==a[k]^a[j-1]) {
                        cout << i << j << k << endl;
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
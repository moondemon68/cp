#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
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
        int n,k,d;
        cin >> n >> k >> d;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int b[k+5];
        memset (b,0,sizeof(b));
        int p=0;
        for (int i=1;i<=d;i++) {
            b[a[i]]++;
            if (b[a[i]] == 1) p++;
        }
        
        int ans=INT_MAX;
        ans = min(ans, p);
        // cerr << p;
        // cerr << endl;
        for (int i=d+1;i<=n;i++) {
            b[a[i-d]]--;
            if (b[a[i-d]] == 0) p--;
            b[a[i]]++;
            if (b[a[i]] == 1) p++;
            // for (int j=1;j<=k;j++) cerr << b[j];
            // cerr << p << " ";
            ans=min(ans, p);
        }
        cout << ans << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
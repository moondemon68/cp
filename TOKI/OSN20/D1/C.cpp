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
    int n,m,k;
    cin >> n >> m >> k;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];

    int cnt[n+5];
    memset (cnt,0,sizeof(cnt));
    int ans = 0;
    
    for (int i=1;i<=n;i++) {
        if (cnt[a[i]] == m) {
            ans++;
            memset (cnt,0,sizeof(cnt));
        }
        cnt[a[i]]++;
    }

    if (ans == 0) cout << 0 << endl;
    else cout << ans+1 << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
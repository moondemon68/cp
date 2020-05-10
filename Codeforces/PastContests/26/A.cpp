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
    bool p[3005];
    memset (p,1,sizeof(p));
    p[1] = 0;
    int n = 3000;
    for (int i=2;i*i<=n;i++) {
        if (!p[i]) continue;
        for (int j=i*i;j<=n;j+=i) {
            p[j] = 0;
        }
    }
    cin >> n;
    int ans = 0;
    for (int i=1;i<=n;i++) {
        int cnt = 0;
        for (int j=1;j<=i;j++) {
            if (i%j == 0 && p[j]) cnt++;
        }
        if (cnt == 2) ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        reverse(a+1,a+n+1);
        bool done[n+5];
        memset(done,0,sizeof(done));
        int cur = a[1];
        cout << cur << " ";
        done[1] = 1;
        for (int i=2;i<=n;i++) {
            int maxi = 0, maxcur = 0;
            for (int j=1;j<=n;j++){
                if (done[j]) continue;
                if (__gcd(a[j], cur) > maxcur) {
                    maxcur = __gcd(a[j], cur);
                    maxi = j;
                }
            }
            cout << a[maxi] << " ";
            done[maxi] = 1;
            cur = __gcd(cur, a[maxi]);
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bitset<64000005> s;
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
        s.reset();
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) {
            int x = a[i];
            for (int j=i+1;j<=n;j++) {
                x += a[j];
                s[x] = 1;
            }
        }
        int cnt = 0;
        for (int i=1;i<=n;i++) {
            if (s[a[i]] == 1) cnt++;
        }
        cout << cnt << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
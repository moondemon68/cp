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
        int a,b,c;
        cin >> a >> b >> c;
        int p[3];
        p[0] = a;
        p[1] = b;
        p[2] = c;
        sort(p, p + 3);
        a = p[2];
        b = p[1];
        c = p[0];
        int ans = 0;
        if (a > 0) {
            a--;
            ans++;
        }
        if (b > 0) {
            b--;
            ans++;
        }
        if (c > 0) {
            c--;
            ans++;
        }
        if (a > 0 && b > 0) {
            a--;
            b--;
            ans++;
        }
        if (a > 0 && c > 0) {
            a--;
            c--;
            ans++;
        }
        if (c > 0 && b > 0) {
            c--;
            b--;
            ans++;
        }
        if (a > 0 && b > 0 && c > 0) {
            a--;
            b--;
            c--;
            ans++;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
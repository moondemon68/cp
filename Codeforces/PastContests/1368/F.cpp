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
    int n;
    cin >> n;
    if (n <= 3){
        cout << 0 << endl;
        return 0;
    }
    bool a[n+5];
    memset (a,0,sizeof(a));
    while (true) {
        int h = -1, f = -1;
        for (int i=0;i<=n;i++) {
            int p = i, q = i+1, r = i+2;
            if (q > n) q -= n;
            if (r > n) r -= n;
            if (p == 0) p += n;
            if (!a[p] && !a[q] && !a[r]) {
                h = q;
                a[h] = 1;
                break;
            }
        }
        for (int i=0;i<=n;i++) {
            int p = i, q = i+1, r = i+2;
            if (q > n) q -= n;
            if (r > n) r -= n;
            if (p == 0) p += n;
            if (!a[p] && !a[q] && !a[r]) {
                f = q;
                a[f] = 1;
                break;
            }
        }
        if (h == -1 || f == -1) {
            cout << 0 << endl;
            return 0;
        }
        cout << 2 << " " << h << " " << f << endl;

        int x;
        cin >> x;
        if (x == -1) {
            assert(1 == 0);
        }
        a[x] = 0;
        int y = x+1;
        if (y > n) y -= n;
        a[y] = 0;
        for (int i=1;i<=n;i++) cout << a[i];
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
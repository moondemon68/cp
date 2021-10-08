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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int kanan[n+5];
    kanan[n] = 1;
    for (int i=n-1;i>=1;i--) {
        if (a[i] > a[i+1]) {
            kanan[i] = kanan[i+1] + 1;
        } else {
            kanan[i] = 1;
        }
    }
    int kiri[n+5];
    for (int i=1;i<=n;i++) kiri[i] = kanan[i];
    for (int i=1;i<=n;i++) {
        int t = 0;
        if (kiri[i] != 1) {
            t = kiri[i];
            sort(kiri + i, kiri + i + t);
            i += t - 1;
        }
    }
    // for (int i=1;i<=n;i++) cout << kanan[i] << " ";
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << kiri[i] << " ";
    // cout << endl;
    int ans = 1;
    // case 1: trivial manjangin doang
    for (int i=1;i<=n;i++) {
        if (kanan[i] == n) ans = n;
        else ans = max(ans, kanan[i] + 1);
    }
    // case 2: ambil yang kiri, ambil yang kanan, duar nyambung
    for (int i=2;i<n;i++) {
        if (a[i-1] > a[i+1] + 1 && kanan[i-1] != kanan[i+1] + 2) {
            ans = max(ans, kiri[i-1] + kanan[i+1] + 1);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
8
5 4 2 0 8 6 9 4
5
5 4 2 0 -1 6 9 4

8
5 4 2 0 8 -4 -6 4
7
5 4 2 0 -1 -4 -6 4

8
1 3 5 1 8 0 1 2
4
1 3 5 1 0.5 0 1 2
*/
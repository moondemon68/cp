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
        for (int i=1;i<=n;i++) cin >> a[i];
        int l=2, r=n;
        int moves = 1, x = a[1], y = 0, cur = a[1];
        int turn = 1;
        while (l <= r) {
            moves++;
            int cnt = 0;
            if (turn == 0) {
                while (cnt <= cur && l <= r) {
                    x += a[l];
                    cnt += a[l];
                    l++;
                }
                cur = cnt;
                turn = 1;
            } else {
                while (cnt <= cur && r >= l) {
                    y += a[r];
                    cnt += a[r];
                    r--;
                }
                cur = cnt;
                turn = 0;
            }
        }
        cout << moves << " " << x << " " << y << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
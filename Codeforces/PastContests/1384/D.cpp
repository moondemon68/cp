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
        int win = 0;
        for (int i=30;i>=0;i--) {
            int cnt = 0;
            for (int j=1;j<=n;j++) {
                if (a[j]&(1<<i)) cnt++;
            }
            // cout << cnt << " ";
            if (cnt % 2 == 1) {
                if (cnt % 4 == 1 && (n-cnt) % 2 == 0) win = 1;
                if (cnt % 4 == 1 && (n-cnt) % 2 == 1) win = 1;
                if (cnt % 4 == 3 && (n-cnt) % 2 == 0) win = -1;
                if (cnt % 4 == 3 && (n-cnt) % 2 == 1) win = 1;
                break;
            }
        }
        if (win == 1) cout << "WIN" << endl;
        else if (win == -1) cout << "LOSE" << endl;
        else cout << "DRAW" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
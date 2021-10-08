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

LL cnt(LL x) {
    LL ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        LL n, s;
        cin >> n >> s;
        LL cur = cnt(n);
        if (cur <= s) {
            cout << 0 << endl;
            continue;
        }
        LL answer = 0;
        LL pow10[20];
        pow10[1] = 10;
        for (int i=2;i<=19;i++) pow10[i] = pow10[i-1] * 10;
        for (int i=1;i<=19;i++) {
            LL l = 1, r = pow10[19-i], ans = -1;
            while (l <= r) {
                LL m = (l+r)/2;
                if (m * pow10[i] >= n) {
                    ans = m;
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            if (ans == -1) continue;
            if (cnt(ans * pow10[i]) <= s) {
                answer = ans * pow10[i] - n;
                break;
            }
        }
        cout << answer << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
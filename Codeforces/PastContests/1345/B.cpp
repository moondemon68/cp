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
    LL a[100005];
    a[0] = 1;
    a[1] = 2;
    LL add = 5;
    for (int i=2;i<=100000;i++) {
        a[i] = a[i-1] + add;
        add += 3;
    }
    while (tc--) {
        int cnt = 0;
        LL x;
        cin >> x;
        while (x > 0) {
            int l = 1, h = 1e5, ans = -1;
            while (l <= h) {
                int m = (l+h)/2;
                if (x >= a[m]) {
                    ans = m;
                    l = m+1;
                } else {
                    h = m-1;
                }
            }
            if (ans == -1) break;
            x -= a[ans];
            cnt++;
        }
        cout << cnt << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
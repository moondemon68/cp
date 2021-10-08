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
    int ans[63250];
    int x = 1, y = 1;
    for (int i=0;i<=63246;i++) {
        ans[i] =  x * y;
        x++;
        if (x > y) swap(x,y);
    }
    while (tc--) {
        int n;
        cin >> n;
        int l = 0, r = 63244, answ = 1;
        while (l <= r) {
            int m = (l + r ) / 2;
            if (ans[m] >= n) {
                answ = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        cout << answ << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
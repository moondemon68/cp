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

int a[300005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        a[i+n] = a[i];
        a[i+2*n] = a[i];
    }
    int mini = MOD, maxi = 0;
    for (int i=1;i<=n;i++) {
        maxi = max (maxi, a[i]);
        mini = min (mini, a[i]);
    }
    if (mini >= (maxi + 1)/2) {
        for (int i=1;i<=n;i++) cout << -1 << ' ';
        return 0;
    }
    int ans[n+5];
    memset (ans,0,sizeof(ans));
    deque<int> d;
    int r = 3*n;
    for (int i=3*n;i>=1;i--) {
        while (!d.empty() && a[d.back()] < (a[i] + 1)/2) {
            r = d.back();
            d.pop_back();
        }
        if (i <= n) ans[i] = r;
        while (!d.empty() && a[d.front()] >= a[i]) d.pop_front();
        d.push_front(i);
        // for (int i=0;i<d.size();i++) cout << a[d[i]] << " ";
        // cout << endl;
    }
    for (int i=1;i<=n;i++) cout << ans[i]-i << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
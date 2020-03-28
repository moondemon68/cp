#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL l[n+5], r[n+5];
    LL x = a[1];
    stack<pii> s;
    for (LL i=1;i<=n;i++) {
        if (a[i] <= x) {
            l[i] = i * a[i];
        } else {
            // for (LL j=i-1;j>=1;j--) {
            //     if (a[j] < a[i]) {
            //         l[i] = l[j] + (i-j) * a[i];
            //         break;
            //     }
            // }
            while (!s.empty() && s.top().fi >= a[i]) {
                s.pop();
            }
            LL j = s.top().se;
            l[i] = l[j] + (i-j) * a[i];
        }
        x = min(a[i], x);
        s.push(mp(a[i], i));
    }
    reverse(a+1,a+n+1);
    x = a[1];
    while (!s.empty()) {
        s.pop();
    }
    for (LL i=1;i<=n;i++) {
        if (a[i] <= x) {
            r[i] = i * a[i];
        } else {
            // for (LL j=i-1;j>=1;j--) {
            //     if (a[j] < a[i]) {
            //         r[i] = r[j] + (i-j) * a[i];
            //         break;
            //     }
            // }
             while (!s.empty() && s.top().fi >= a[i]) {
                s.pop();
            }
            LL j = s.top().se;
            r[i] = r[j] + (i-j) * a[i];
        }
        x = min(a[i], x);
        s.push(mp(a[i], i));
    }
    reverse(r+1,r+n+1);
    reverse(a+1,a+n+1);
    x = 1;
    LL mx = 0;
    for (LL i=1;i<=n;i++) {
        if (l[i] + r[i] - a[i] > mx) {
            mx = l[i] + r[i] - a[i];
            x = i;
        }
    }
    LL p = a[x];
    for (LL i=x+1;i<=n;i++) {
        p = min(p, a[i]);
        a[i] = p;
    }
    p = a[x];
    for (LL i=x-1;i>=1;i--) {
        p = min(p, a[i]);
        a[i] = p;
    }
    for (LL i=1;i<=n;i++) cout << a[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
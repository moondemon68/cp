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
    LL ans = 0, cur = 0;
    priority_queue<LL, vector<LL>, greater<LL>> p;
    for (int i=1;i<=n;i++) {
        if (cur + a[i] >= 0) {
            cur += a[i];
            ans++;
            if (a[i] < 0) p.push(a[i]);
        } else {
            if (p.empty()) continue;
            else if (p.top() < a[i]) {
                LL tmp = p.top();
                p.pop();
                p.push(a[i]);
                cur += a[i] - tmp;
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
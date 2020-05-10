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
        LL a[n+5], ans = 0;
        for (int i=1;i<=n;i++) cin >> a[i];
        priority_queue<LL> p;
        LL last = MOD;
        for (int i=1;i<=n;i++) {
            if (p.empty()) p.push(a[i]);
            else if (p.top() * a[i] < 0) {
                ans += p.top();
                last = p.top();
                while (!p.empty()) {
                    p.pop();
                }
                p.push(a[i]);
            } else {
                p.push(a[i]);
            }
        }
        if (!p.empty() && (last * p.top() < 0 || last == MOD)) ans += p.top();
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
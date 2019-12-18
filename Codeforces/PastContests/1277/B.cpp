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
        priority_queue<int> p;
        int ans=0;
        for (int i=1;i<=n;i++) p.push(a[i]);
        while (!p.empty()) {
            if (p.top() % 2 == 1) {
                p.pop();
                continue;
            }
            int cnt = 1, cur = p.top();
            p.pop();
            ans++;
            while (!p.empty() && p.top() == cur) {
                p.pop();
                cnt++;
            }
            cur/=2;
            if (cur % 2 == 0) {
                for (int i=1;i<=cnt;i++) p.push(cur);
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
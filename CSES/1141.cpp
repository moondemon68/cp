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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int l = 1, r = 1;
    int ans = 0;
    set<int> s;
    while (r <= n) {
        if (l == r) {
            s.insert(a[r]);
            r++;
        } else {
            if (s.find(a[r]) == s.end()) {
                s.insert(a[r]);
                r++;
            } else {
                while (s.find(a[r]) != s.end()) {
                    s.erase(a[l]);
                    l++;
                }
                s.insert(a[r]);
                r++;
            }
        }
        ans = max(ans, (int)s.size());
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
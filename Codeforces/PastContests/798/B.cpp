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
    string a[n+5];
    int ans = INT_MAX;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=0;i<a[1].size();i++) {
        string t = a[1];
        int cnt = 0;
        for (int j=1;j<=i;j++) {
            t += t[0];
            cnt++;
            t.erase(t.begin());
        }
        for (int j=2;j<=n;j++) {
            string s = a[j];
            while (s != t) {
                cnt++;
                if (cnt > 100000) break;
                s += s[0];
                s.erase(s.begin());
            }
        }
        ans = min(ans, cnt);
    }
    if (ans > 100000) cout << -1 << endl;
    else cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
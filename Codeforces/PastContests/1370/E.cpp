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
    string s,t;
    cin >> s >> t;
    int z = 0, o = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == '0') z++; else o++;
    }
    for (int i=0;i<t.size();i++) {
        if (t[i] == '0') z--; else o--;
    }
    if (z != 0 | o != 0) {
        cout << -1 << endl;
        return 0;
    }
    int a[n+5];
    for (int i=0;i<s.size();i++) {
        a[i] = s[i]-t[i];
    }
    int ans = 0, cur = 0;
    for (int i=0;i<n;i++) {
        cur += a[i];
        ans = max(ans, cur);
        if (cur < 0) cur = 0;
    }
    for (int i=0;i<n;i++) a[i] *= -1;
    int ans2 = 0;
    cur = 0;
    for (int i=0;i<n;i++) {
        cur += a[i];
        ans2 = max(ans2, cur);
        if (cur < 0) cur = 0;
    }
    cout << max(ans, ans2) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
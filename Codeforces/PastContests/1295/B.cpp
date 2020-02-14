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
        int n,x;
        cin >> n >> x;
        string s;
        cin >> s;
        int a[n+5];
        memset(a,0,sizeof(a));
        a[0] = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '0') a[i+1] = a[i] + 1;
            else a[i+1] = a[i] - 1;
        }
        if (a[n] == 0 && x == 0) {
            cout << -1 << endl;
            continue;
        }
        if (a[n] == 0) {
            bool y = 0;
            for (int i=0;i<n;i++) {
                if (a[i] == x) y=1;
            }
            if (y) {
                cout << -1 << endl;
                continue;
            }
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (a[n]!=0 && (x-a[i]) % a[n] == 0 && (x-a[i]) / a[n] >= 0) ans++;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
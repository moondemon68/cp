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
        string s;
        cin >> s;
        int a[n+5];
        memset (a,0,sizeof(a));
        for (int i=0;i<s.size();i++) {
            a[i+1] = s[i]-'0';
        }
        int cnt = 0;
        vector<int> v;
        for (int i=1;i<=n+1;i++) {
            if (a[i] == 1) {
                cnt++;
            }
        }
        for (int i=1;i<=n;i++) a[i] += a[i-1];
        LL ans = 0;
        for (int i=1;i<=n;i++) {
            for (int j=i;j<=n;j++) {
                if (j-i+1 == a[j]-a[i-1]) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
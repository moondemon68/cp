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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int c[35];
        memset (c,0,sizeof(c));
        for (int i=0;i<s.size();i++) c[s[i]-'a']++;
        int ans = 0;
        for (int i=1;i<=n;i++) {
            int req = __gcd(i,k);
            // cout << req << " ";
            for (int j=0;j<26;j++) {
                req -= c[j]/(i/__gcd(i,k));
            }
            if (req <= 0) ans = i;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
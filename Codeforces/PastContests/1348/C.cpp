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
        sort(s.begin(), s.end());
        string ans = "";
        int cnt = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == s[0]) cnt++;
        }
        if (cnt < k) {
            cout << s[k-1] << endl;
        } else {
            ans += s[0];
            if (s[k] == s.back()) {
                for (int i=1;i<=(n-k+k-1)/k;i++) {
                    ans += s[k];
                }
            } else {
                for (int i=k;i<s.size();i++) ans += s[i];
            }
            cout << ans << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
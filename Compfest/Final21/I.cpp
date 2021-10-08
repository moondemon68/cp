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
    string s;
    cin >> s;
    int ans = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == '0') {
            ans = max(ans, 0);
        } else if (s[i] == '1') {
            ans = max(ans, 1);
        } else if (s[i] <= '3') {
            ans = max(ans, 2);
        } else if (s[i] <= '7') {
            ans = max(ans, 3);
        } else {
            ans = max(ans, 4);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
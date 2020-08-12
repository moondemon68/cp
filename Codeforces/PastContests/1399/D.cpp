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
        int ans[n+5];
        memset (ans,0,sizeof(ans));
        stack<int> z,o;
        int cnt = 1;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '1') {
                if (z.empty()) {
                    ans[i] = cnt;
                    o.push(i);
                    cnt++;
                } else {
                    ans[i] = ans[z.top()];
                    z.pop();
                    o.push(i);
                }
            } else {
                if (o.empty()) {
                    ans[i] = cnt;
                    z.push(i);
                    cnt++;
                } else {
                    ans[i] = ans[o.top()];
                    o.pop();
                    z.push(i);
                }
            }
        }
        cout << cnt-1 << endl;
        for (int i=0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
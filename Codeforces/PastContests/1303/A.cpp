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
        string s;
        cin >> s;
        int p = -1, q = -1;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '1') {
                p = i;
                break;
            }
        }
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i] == '1') {
                q = i;
                break;
            }
        }
        if (p == -1 || q == -1) {
            cout << 0 << endl;
            continue;
        }
        int ans=0;
        for (int i=p;i<=q;i++) {
            if (s[i] == '0') ans++;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
        string s;
        cin >> s;
        if (s.size() % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        int cur = 0;
        bool y = 1;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '(') {
                cur++;
            } else if (s[i] == ')') {
                cur--;
                if (cur < 0) {
                    y = 0;
                }
            } else {
                cur++;
            }
        }
        if (s[s.size()-1] == '(') y = 0;
        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
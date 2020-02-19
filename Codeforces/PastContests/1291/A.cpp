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
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool y = 0;
        for (int i=0;i<s.size();i++) {
            for (int j=i+1;j<s.size();j++) {
                if ((s[j]-'0')%2 == 1 && (s[i]-'0')%2 == 1) {
                    y = 1;
                    cout << s[i] << s[j] << endl;
                    break;
                }
            }
            if (y) break;
        }
        if (!y) cout << -1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
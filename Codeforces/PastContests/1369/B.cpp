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
    while(tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        if (s[0] == '1') {
            bool y = 0;
            for (int i=0;i<s.size();i++) {
                if (s[i] == '0') y = 1;
            }
            if (y) {
                cout << 0;
                for (int i=s.size()-1;i>=0;i--) {
                    if (s[i] == '1') cout << s[i];
                    else break;
                }
                cout << endl;
            } else {
                cout << s << endl;
            }
        } else {
            int p = -1;
            for (int i=0;i<s.size();i++) {
                if (s[i] == '0') {
                    p = i;
                    cout << s[i];
                }
                else break;
            }

            bool y = 0;
            for (int i=p+1;i<s.size();i++) {
                if (s[i] == '0') y = 1;
            }
            if (y) {
                cout << 0;
                for (int i=s.size()-1;i>=p+1;i--) {
                    if (s[i] == '1') cout << s[i];
                    else break;
                }
                cout << endl;
            } else {
                for (int i=p+1;i<s.size();i++) cout << s[i];
                cout << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
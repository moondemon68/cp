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
        bool genap = 0, nol = 0;;
        int tot = 0;
        for (int i=0;i<s.size();i++) {
            tot += s[i]-'0';
            if ((s[i]-'0') == 0) nol = 1;            
        }
        bool edit = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '0' && !edit) {
                edit = 1;
                s[i] = '9';
            }
        }
        for (int i=0;i<s.size();i++) {
            if ((s[i] - '0') % 2 == 0) genap = 1;
        }
        if (genap && nol && tot % 3 == 0) cout << "red" << endl; else cout << "cyan" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
        string a = "", b = "";
        bool y = 1;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '2' && y) {
                a += '1';
                b += '1';
            }
            else if (s[i] == '2' && !y) {
                a += '0';
                b += '2';
            }
            else if (s[i] == '1' && y) {
                a += '1';
                b += '0';
                y = 0;
            }
            else if (s[i] == '1' && !y) {
                a += '0';
                b += '1';
            }
            else if (s[i] == '0' && y) {
                a += '0';
                b += '0';
            }
            else if (s[i] == '0' && !y) {
                a += '0';
                b += '0';
            }
        }
        cout << a << endl << b << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
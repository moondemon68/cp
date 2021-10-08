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
    ifstream cin("A1_input.txt");
    ofstream cout("A1_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0, type = 0;  // type: 0 FO, 1 FX
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'O' || s[i] == 'X') {
                p = i;
                break;
            }
        }
        int cur = 0;
        if (s[p] == 'O') type = 0;
        else type = 1;
        for (int i = 0; i < s.size(); i++) {
            if (type == 0) {
                if (s[i] == 'O' || s[i] == 'F') {
                    // pass
                } else {
                    type = 1;
                    cur++;
                }
            } else {
                if (s[i] == 'X' || s[i] == 'F') {
                    // pass
                } else {
                    type = 0;
                    cur++;
                }
            }
            ans = cur;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
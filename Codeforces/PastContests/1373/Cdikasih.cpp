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
    int res = 0;
    for (int i=0;i<MOD;i++) {
        int cur = i;
        bool ok = 1;
        for (int j=0;j<s.size();j++) {
            res++;
            if (s[j] == '+') cur++;
            else cur--;
            if (cur < 0) {
                ok = 0;
                break;
            }
        }
        if (ok) break;
    }
    cout << res << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
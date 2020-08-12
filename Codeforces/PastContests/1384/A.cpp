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
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        bool y = 0;
        string s = "";
        for (int i=1;i<=200;i++) s += 'a';
        cout << s << endl;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=200;j++) {
                if (j > a[i]) {
                    if (s[j-1] == 'a') s[j-1] = 'b';
                    else s[j-1] = 'a';
                }
            }
            cout << s << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
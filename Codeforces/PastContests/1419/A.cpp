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
        bool p = 0;
        for (int i=1-n%2;i<n;i+=2) {
            if ((s[i]-'0')%2 == n%2) p = 1;
        }
        if (n%2 == 0 && p) cout << 2 << endl;
        else if (n%2 == 0 && !p) cout << 1 << endl;
        else if (n%2 == 1 && p) cout << 1 << endl;
        else cout << 2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
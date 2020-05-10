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
        int n,k;
        cin >> n >> k;
        string s = "";
        for (int i=1;i<=n;i++) s += 'a';
        for (int i=1;i<n;i++) {
            k -= i;
            if (k <= 0) {
                // cout << i << " " << k + i - 1 << endl;
                s[n-i-1] = 'b';
                s[n-(k+i-1)-1] = 'b';
                cout << s << endl;
                break;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
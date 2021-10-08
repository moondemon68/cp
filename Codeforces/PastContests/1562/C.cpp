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
        int a[n+5];
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++) {
            a[i] = s[i-1] - '0';
        }
        bool done = 0;
        for (int i=n/2+1;i<=n;i++) {
            if (a[i] == 0) {
                cout << 1 << " " << i << " " << 1 << " " << i-1 << endl;
                done = 1;
                break;
            }
        }
        if (!done) {
            for (int i=1;i<=n/2;i++) {
                if (a[i] == 0) {
                    cout << i << " " << n << " " << i+1 << " " << n << endl;
                    done = 1;
                    break;
                }
            }
        }
        if (!done) {
            if (n % 2 == 0) {
                cout << 1 << " " << n << " " << 1 << " " << n/2 << endl;
            } else {
                cout << 1 << " " << n-1 << " " << 1 << " " << (n-1)/2 << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
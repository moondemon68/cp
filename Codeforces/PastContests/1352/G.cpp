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
        if (n <= 3) cout << -1 << endl;
        else if (n%2 == 0) {
            for (int i=n;i>=6;i-=2) cout << i << " ";
            cout << "2 4 1 3 ";
            for (int i=5;i<=n;i+=2) cout << i << " ";
            cout << endl;
        } else {
            for (int i=n;i>=1;i-=2) cout << i << " ";
            cout << "4 2 ";
            for (int i=6;i<=n;i+=2) cout << i << " ";
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
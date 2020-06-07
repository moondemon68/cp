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
        vector<int> a;
        int x = 1, tot = 0;
        while (tot < n) {
            tot += x;
            a.pb(x);
            x *= 2;
        }
        if (tot > n) {
            tot -= a.back();
            a.back() = n-tot;
        }
        sort (a.begin(), a.end());
        cout << a.size()-1 << endl;
        for (int i=0;i<a.size()-1;i++) {
            cout << a[i+1]-a[i] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
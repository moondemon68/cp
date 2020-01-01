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
        int a[4];
        cin >> a[0] >> a[1] >> a[2];
        // int m = min(a[0], min(a[1], a[2]));
        // a[0]-=m;
        // a[1]-=m;
        // a[2]-=m;
        sort (a,a+3);
        int p = a[0] + a[1], q = a[2];
        if (q <= p+1) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
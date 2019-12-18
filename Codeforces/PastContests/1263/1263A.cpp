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
        int a[4];
        cin >> a[1] >> a[2] >> a[3];
        sort (a+1,a+4);
        int x = a[1]+a[2], y= a[3];
        //cout << x << " " << y << endl;
        if (x < y) cout << x;
        else cout  << (x+y)/2;
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
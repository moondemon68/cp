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
        int n,x;
        cin >> x >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        int l=1,r=n,y=0;
        while (l<r) {
            if (a[l] + a[r] == x) {
                cout << a[l] << " " << a[r] << endl;
                y=1;
                break;
            } else if (a[l] + a[r] > x) {
                r--;
            } else l++;
        }
        if (!y) cout << "!OK" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
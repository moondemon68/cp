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
    int q;
    cin >> q;
    while (q--) {
        int n,k;
        cin >> n >> k;
        int a[n+5];
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            a[i]%=2;
        }
        int p=0;
        vector<int> ans;
        for (int i=1;i<=n;i++) {
            if (a[i]==1) {
                if (k==1) {
                    p+=a[i];
                } else {
                    ans.pb(i);
                    k--;
                }
            }
        }
        if (p%2==0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (auto x:ans) cout << x << " ";
            cout << n << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
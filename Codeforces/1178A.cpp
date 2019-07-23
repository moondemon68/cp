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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int p=a[1],q=0;
    vector<int> ans;
    ans.pb(1);
    for (int i=2;i<=n;i++) {
        if (a[i]*2<=a[1]) {
            ans.pb(i);
            p+=a[i];
        } else q+=a[i];
    }
    if (p>q) {
        cout << ans.size() << endl;
        for (int i=0;i<(int)ans.size();i++) cout << ans[i] << " ";
    } else cout << 0 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n,p;
    cin >> n >> p;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    vector<int> ans;
    for (int i=a[1];i<=max(a[n], p) + 100000;i++) {
        int cnt = 0, po = i;
        bool y = 1;
        for (int j=1;j<=n;j++) {
            if (a[j] <= i) {
                po++;
                cnt = j;
            } else {
                if (po >= a[j]) {
                    po++;
                } else {
                    y = 0;
                    break;
                }
            }
        }
        // cout << i <<  " " << cnt << endl;
        for (int j=1;j<=cnt;j++) {
            if (j % p == 0) y = 0;
        }
        if (y) ans.pb(i);
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
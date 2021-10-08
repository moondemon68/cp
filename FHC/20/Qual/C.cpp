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

pii a[800005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("timber_input.txt");
    ofstream cout("timber_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
        sort (a+1,a+n+1);
        vector<pii> kiri;
        map<int,int> right, left;
        for (int i=1;i<=n;i++) {
            kiri.pb({a[i].fi-a[i].se, a[i].se});
        }
        sort (kiri.begin(), kiri.end());
        reverse(kiri.begin(), kiri.end());
        int ans = 0;
        for (auto k : kiri) {
            left[k.fi] = max(left[k.fi], left[k.fi+k.se]+k.se);
            ans = max(ans, left[k.fi]);
        }
        for (int i=1;i<=n;i++) {
            int mid = 0;
            // ke kanan
            mid = a[i].fi+a[i].se;
            right[mid] = max(a[i].se+right[a[i].fi], right[mid]);
            ans = max(ans, right[mid] + left[mid]);
            // for (auto x : right) {
            //     if (x.se != 0) cout << x.fi << " " << x.se << endl;
            // }
            // cout << start << " " << mid << endl;
        }
        cout << "Case #" << t << ": " << ans << "\n";
        // for (auto x : left) {
        //     cout << x.fi << " " << x.se << endl;
        // }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
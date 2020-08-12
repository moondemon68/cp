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

void check(string a, string b, vector<int> v) {
    for (auto x : v) {
        for (int j=1;j<=x;j++) {
            if (a[j-1] == '0') a[j-1] = '1'; else a[j-1] = '0';
        }
        reverse(a.begin(), a.begin()+x);
        if (a == b) break;
    }
    if (a == b) cout << "YES" << endl; else cout << "NO" << endl;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        vector<int> ans;
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        string s = a, t = b;
        
        for (int i=0;i<n-1;i++) {
            if (a[i] != a[i+1]) {
                ans.pb(i+1);
                a[i] = a[i+1];
            }
        }
        if (a.back() == '1') ans.pb(n);

        vector<int> ans2;
        for (int i=0;i<n-1;i++) {
            if (b[i] != b[i+1]) {
                ans2.pb(i+1);
                b[i] = b[i+1];
            }
        }
        if (b.back() == '1') ans2.pb(n);

        cout << ans.size() + ans2.size() << " ";
        for (auto x : ans) cout << x << " ";
        reverse(ans2.begin(), ans2.end());
        for (auto x : ans2) cout << x << " ";
        cout << endl;
        for (auto x : ans2) ans.pb(x);
        // check(s, t, ans);
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
10
0110011011
1000110100
*/
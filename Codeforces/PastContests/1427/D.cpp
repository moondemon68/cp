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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    bool up = 1;
    bool answer = 0;
    vector<vector<int>> ans;
    while (1) {
        bool y = 1;
        for (int i=1;i<n;i++) {
            if (a[i] > a[i+1]) y = 0;
        }
        if (y) break;
        vector<int> v;
        int cnt = 1;
        for (int i=1;i<=n;i++) {
            if (up) {
                if (a[i] < a[i+1] && i < n) {
                    cnt++;
                } else {
                    // if (i == n) cnt++;
                    v.pb(cnt);
                    cnt = 1;
                }
            } else {
                if (a[i] > a[i+1] && i < n) {
                    cnt++;
                } else {
                    // if (i == n) cnt++;
                    v.pb(cnt);
                    cnt = 1;
                }
            }
        }
        up = !up;
        answer = 1;
        vector<int> anstemp;
        anstemp.pb(v.size());
        for (auto x : v) anstemp.pb(x);
        ans.pb(anstemp);
        // cout << v.size() << " ";
        // for (auto x : v) cout << x << " ";
        // cout << endl;

        for (int i=0;i<v.size()-1;i++) {
            v[i+1] += v[i];
        }

        vector<int> p;
        for (int i=v.size()-2;i>=-1;i--) {
            int x;
            if (i == -1) x = 1; else x = v[i]+1;
            for (int j=x;j<=v[i+1];j++) {
                p.pb(a[j]);
            }
        }
        for (int i=1;i<=n;i++) {
            a[i] = p[i-1];
        }

        // for (int i=1;i<=n;i++) cout << a[i] << " ";
        // cout << endl;
    }
    cout << ans.size() << endl;
    for (auto v : ans) {
        for (auto x : v) cout << x << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
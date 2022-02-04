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

int eval(vector<int> v, vector<int> w) {
    if (v[0] == 0) return 0;
    int ret = 0, cur = 0;
    vector<int> a;
    bool y = 0;
    // cout << endl;
    // for (int i=0;i<v.size();i++) cout << v[i];
    // cout << endl;
    // for (int i=0;i<v.size();i++) cout << w[i];
    // cout << endl;
    for (int i=0;i<v.size();i++) {
        cur += v[i];
        if (w[i]) {
            if (i < v.size()-1 && v[i+1] == 0) {
                y = 1;
                break;
            }
            a.pb(cur);
            cur = 0;
        } else {
            cur *= 2;
        }
    }
    if (!w[v.size()-1]) a.pb(cur/2);
    if (y) return 0;
    for (int l=0;l<a.size();l++) {
        ret |= a[l];
        // cout << a[l] << " ";
    }
    // cout << ret << "; ";
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k;
        cin >> n >> k;
        int ans = 0, semua = (1 << n) - 1;
        for (int i=0;i<(1<<k);i++) {
            vector<int> v;
            int x = i;
            for (int j=0;j<k;j++) {
                v.pb(x % 2);
                x /= 2;
            }
            int ans2 = 0;
            for (int j=0;j<(1<<(k-1));j++) {
                vector<int> w;
                int x = j;
                for (int l=0;l<k;l++) {
                    w.pb(x % 2);
                    x /= 2;
                }
                w.pb(0);
                bool valid = 0;
                for (int l=0;l<k;l++) {
                    if (v[0] == 0) {
                        valid = 0;
                        break;
                    }
                    vector<int> v2, w2;
                    for (int m=l;m<k;m++) {
                        v2.pb(v[m]);
                        w2.pb(w[m]);
                    }
                    if (eval(v2, w2) == semua) {
                        valid = 1;
                        break;
                    }
                }
                for (int m=0;m<k;m++) {
                    if (w[m] && v[m+1] == 0) {
                        valid = 0;
                        break;
                    }
                }
                if (valid) {
                    ans2++;
                }
            }
            ans += ans2;
            // for (auto x : v) {
            //     cout << x;
            // }
            // cout << " " << ans2;
            // cout << endl;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
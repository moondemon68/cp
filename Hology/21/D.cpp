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

LL fpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

int p[8];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tmp = 1;
    for (int i=1;i<=8;i++) {
        p[i-1] = tmp;
        tmp *= 31;
    }
    // string ss = "zzzzzzz";
    // int tg = 0;
    // for (int i=0;i<ss.size();i++) {
    //     tg += ss[i] * p[ss.size() - i - 1];
    // }
    // cout << tg << endl;

    int n;
    cin >> n;
    int h;
    cin >> h;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int a = s.size();
    vector<pair<int, string>> l, r, e;
    vector<string> ans;
    if (n <= 3) {
        for (int i=0;i<fpow(a, n);i++) {
            vector<int> v;
            string v2 = "";
            int x = i;
            for (int j=0;j<n;j++) {
                v.pb(s[x % a]);
                v2 += s[x % a];
                x /= a;
            }
            int tot = 0;
            for (int j=0;j<n;j++) {
                tot += v[j] * p[n - j - 1];
            }
            l.pb({tot, v2});
        }
        for (int i=0;i<l.size();i++) {
            if (l[i].fi == h) {
                ans.pb(l[i].se);
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.empty()) {
            cout << "-" << endl;
        } else {
            for (auto x : ans) {
                cout << x << endl;
            }
        }
    } else if (n <= 6) {
        for (int i=0;i<fpow(a, 3);i++) {
            string v2 = "";
            int x = i;
            int tot = 0;
            for (int j=0;j<3;j++) {
                tot += s[x % a] * p[n - j - 1];
                v2 += s[x % a];
                x /= a;
            }
            l.pb({tot, v2});
        }
        for (int i=0;i<fpow(a, n-3);i++) {
            string v2 = "";
            int x = i;
            int tot = 0;
            for (int j=0;j<n-3;j++) {
                tot += s[x % a] * p[n - 3 - j - 1];
                v2 += s[x % a];
                x /= a;
            }
            r.pb({tot, v2});
        }
        sort(r.begin(), r.end());
        for (int i=0;i<l.size();i++) {
            int target = h - l[i].fi;
            int low = 0, high = r.size() - 1, answer = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (r[mid].fi < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                    answer = mid;
                }
            }
            while (answer < r.size() && r[answer].fi + l[i].fi == h) {
                ans.pb(l[i].se + r[answer].se);
                answer++;
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.empty()) {
            cout << "-" << endl;
        } else {
            for (auto x : ans) {
                cout << x << endl;
            }
        }
    } else if (n <= 8) {
        for (int i=0;i<fpow(a, 3);i++) {
            string v2 = "";
            int x = i;
            int tot = 0;
            for (int j=0;j<3;j++) {
                tot += s[x % a] * p[n - j - 1];
                v2 += s[x % a];
                x /= a;
            }
            l.pb({tot, v2});
        }
        for (int i=0;i<fpow(a, 3);i++) {
            string v2 = "";
            int x = i;
            int tot = 0;
            for (int j=0;j<3;j++) {
                tot += s[x % a] * p[n - 3 - j - 1];
                v2 += s[x % a];
                x /= a;
            }
            r.pb({tot, v2});
        }
        sort(r.begin(), r.end());
        for (int i=0;i<fpow(a, n-6);i++) {
            string v2 = "";
            int x = i;
            int tot = 0;
            for (int j=0;j<n-6;j++) {
                tot += s[x % a] * p[n - 6 - j - 1];
                v2 += s[x % a];
                x /= a;
            }
            e.pb({tot, v2});
        }
        // cout << r[0].fi << " " << r[0].se << endl;
        // cout << r.back().fi << " " << r.back().se << endl;
        for (int i=0;i<l.size();i++) {
            if (h - l[i].fi - r[0].fi < 0 || h - l[i].fi - r.back().fi > 4000) {
                continue;
            }
            for (int j=0;j<e.size();j++) {
                int target = h - l[i].fi - e[j].fi;
                int low = 0, high = r.size() - 1, answer = 0;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (r[mid].fi < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                        answer = mid;
                    }
                }
                while (answer < r.size() && (r[answer].fi + l[i].fi + e[j].fi) == h) {
                    ans.pb(l[i].se + r[answer].se + e[j].se);
                    answer++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.empty()) {
            cout << "-" << endl;
        } else {
            for (auto x : ans) {
                cout << x << endl;
            }
        }
    }
    return 0;
}
/*
8
-1910022912
zzzzzzzz

7
215481018
zzzzzzz
*/
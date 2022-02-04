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

const int MAXN = 1005;
int a[MAXN];
int c[MAXN];
int query = 0;

int help(int l, int r) {
    query++;
    vector<int> h = {0,1,2,1,3,2,1,4,3,2,3,2};
    set<int> s;
    for (int i = l; i <= r; i++) {
        s.insert(h[i]);
    }
    return s.size();
}
vector<pii> range;
map<pii, int> memo;

int find(int l, int r) {
    for (int i = 0; i < range.size()-1; i++) {
        if (range[i].fi == l && range[i+1].se == r) {
            return 2;
        }
    }
    return -1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int n, q;
    cin >> n >> q;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    int color = 1;
    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                int l = i + 1, r = n, ans = i;
                while (l <= r) {
                    int m = (l + r) / 2;
                    cout << "? " << i << " " << m << endl;
                    int x;
                    cin >> x;
                    if (x == 1) {
                        ans = m;
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                for (int j = i; j <= ans; j++) {
                    a[j] = color;
                }
                color++;
            }
        }
    } else if (t == 2) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                int m = i + 1, ans = i;
                while (m <= n) {
                    cout << "? " << i << " " << m << endl;
                    int x;
                    cin >> x;
                    if (x == 1) {
                        ans = m;
                    } else {
                        break;
                    }
                    m++;
                }
                for (int j = i; j <= ans; j++) {
                    a[j] = color;
                }
                color++;
            }
        }
    } else if (t != 5) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                int m = i + 1, ans = i;
                while (m <= n) {
                    int x;
                    // cout << "? " << i << " " << m << endl;
                    // cin >> x;
                    x = help(i, m);
                    if (x == 1) {
                        ans = m;
                    } else {
                        break;
                    }
                    m++;
                }
                range.pb({i, ans});
                for (int j = i; j <= ans; j++) {
                    a[j] = 1;
                }
            }
        }
        c[0] = 1;
        c[1] = 2;
        if (t == 3) {
            for (int i = 2; i < range.size(); i++) {
                cout << "? " << range[i-2].fi << " " << range[i].se << endl;
                int x;
                cin >> x;
                if (x == 2) {
                    c[i] = c[i-2];
                } else {
                    c[i] = 6 - c[i-1] - c[i-2]; // get complement of 1, 2, 3
                }
            }
        } else if (t == 6) {
            color = 2;
            for (int i = 2; i < range.size(); i++) {
                set<int> s;
                map<int, int> m;
                int cur = i;
                while (s.size() < color) {
                    cur--;
                    s.insert(c[cur]);
                    m[c[cur]]++;
                }
                cout << "? " << range[cur].fi << " " << range[i].se << endl;
                int x;
                cin >> x;
                if (x == color) {
                    for (int j = cur; j < i; j++) {
                        m[c[j]]--;
                        if (m[c[j]] == 0) {
                            s.erase(c[j]);
                            if ((j+1) == i) {
                                x = 1;
                            } else {
                                cout << "? " << range[j+1].fi << " " << range[i].se << endl;
                                cin >> x;
                            }
                            if (x == s.size() + 1) {
                                c[i] = c[j];
                                break;
                            }
                        }
                    }
                } else {
                    color++;
                    c[i] = color;
                }
            }
        } else if (t == 7) {
            color = 2;
            for (int i = 2; i < range.size(); i++) {
                set<int> s;
                map<int, int> m;
                int cur = i;
                while (s.size() < color) {
                    cur--;
                    s.insert(c[cur]);
                    m[c[cur]]++;
                }
                int x;
                cout << "? " << range[cur].fi << " " << range[i].se << endl;
                cin >> x;
                if (x == color) {
                    vector<pii> v;
                    for (int j = cur; j < i; j++) {
                        m[c[j]]--;
                        if (m[c[j]] == 0) {
                            s.erase(c[j]);
                            v.pb({j+1, s.size() + 1});
                        }
                    }

                    // binser
                    int l = 0, r = v.size() - 1, ans = v.size() - 1;
                    while (l <= r) {
                        int mid = (l + r) / 2;
                        if (v[mid].fi == i) {
                            x = 1;
                        } else {
                            cout << "? " << range[v[mid].fi].fi << " " << range[i].se << endl;
                            cin >> x;
                        }
                        if (x < v[mid].se) {
                            l = mid + 1;
                        } else {
                            ans = mid;
                            r = mid - 1;
                        }
                    }
                    c[i] = c[v[ans].fi-1];
                } else {
                    color++;
                    c[i] = color;
                }
            }
        } else if (t == 4) {
            for (int i = 2; i < range.size(); i++) {
                int x;
                // cout << "? " << range[i-2].fi << " " << range[i].se << endl;
                // cin >> x;
                x = help(range[i-2].fi, range[i].se);
                if (x == 2) {
                    c[i] = c[i-2];
                } else {
                    c[i] = 3;
                    break;
                }
            }
            color = 3;
            for (int i = 2; i < range.size(); i++) {
                if (c[i] > 0) continue;
                set<int> s;
                map<int, int> m;
                int cur = i;
                while (s.size() < color) {
                    cur--;
                    s.insert(c[cur]);
                    m[c[cur]]++;
                }
                int x;
                vector<pii> v;
                for (int j = cur; j < i; j++) {
                    m[c[j]]--;
                    if (m[c[j]] == 0) {
                        s.erase(c[j]);
                        if (j+1 < i && c[j] != 0) v.pb({j+1, s.size() + 1});
                    }
                }
                cout << i << endl;
                for (auto p : v) cout << p.fi << " " << p.se << endl;
            }
        }
        for (int i = 0; i < range.size(); i++) {
            for (int j = range[i].fi; j <= range[i].se; j++) {
                a[j] = c[i];
            }
        }
    } else {    // t == 5
        int x;
        int cur = 1;
        a[1] = 1;
        for (int i = 2; i <= n; i++) {
            cout << "? 1 " << i << endl;
            cin >> x;
            if (x == i) {
                a[i] = i;
                cur = i;
            } else {
                break;
            }
        }
        if (cur != n) {
            cur++;
            for (int i = 2; i < cur; i++) {
                cout << "? " << i << " " << cur << endl;
                cin >> x;
                if (x == cur - i + 1) {
                    a[cur] = i - 1;
                    break;
                }
            }
            for (int i = cur + 1; i <= n; i++) {
                a[i] = cur;
                cur++;
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cerr << query << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
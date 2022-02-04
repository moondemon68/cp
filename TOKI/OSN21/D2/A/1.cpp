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

set<vector<int>> s;

void solve(vector<int> v) {
    if (v.size() == 1) {
        s.insert(v);
        return;
    }
    for (int i = 0; i < v.size() - 1; i++) {
        vector<int> w;
        for (int j = 0; j < i; j++) {
            w.pb(v[j]);
        }
        w.pb(min(v[i], v[i+1]));
        for (int j = i+2; j < v.size(); j++) {
            w.pb(v[j]);
        }
        if (s.find(w) == s.end()) {
            s.insert(w);
            solve(w);
        }
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    s.insert(v);
    solve(v);
    cout << s.size() % MOD << endl;
    for (auto x : s) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
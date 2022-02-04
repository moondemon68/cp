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
    ofstream cout("brute.txt");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 1; j <= i; j++) v.pb(j);
        do {
            s.clear();
            solve(v);
            for (auto x : v) cout << x << " ";
            cout << "-> ";
            for (int j = 0; j < v.size() - 1; j++) {
                if (v[j] < v[j+1]) cout << "+"; else cout << "-";
            }
            cout << " -> ";
            int cnt = 0;
            for (int j=0;j<v.size();j++) {
                for (int k=j+1;k<v.size();k++) {
                    if (v[j] > v[k]) cnt++;
                }
            }
            cout << cnt << " -> ";
            cout << s.size() + 1 << endl;
        } while (next_permutation(v.begin(), v.end()));
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
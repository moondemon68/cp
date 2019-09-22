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
    int n,m;
    cin >> n >> m;
    multiset<int,greater<int>> s;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i=1;i<=m;i++) {
        int x;
        cin >> x;
        auto p = s.lower_bound(x);
        if (p == s.end()) {
            cout << -1 << endl;
        } else {
            cout << *p << endl;
            s.erase(p);
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

set<int> s;
multiset<int> diff;

void ins(int x) {
    if (s.empty()) {
        s.insert(x);
        return;
    }
    if (s.size() == 1) {
        s.insert(x);
        // cout << (*s.rbegin()) << " " << (*s.begin()) << endl;
        diff.insert((*s.rbegin()) - (*s.begin()));
        return;
    }
    auto pp = s.upper_bound(x), pq = (s.lower_bound(x));
    if (pp == s.end()) {
        diff.insert(x - (*s.rbegin()));
        s.insert(x);
    } else if (pq == s.begin()) {
        pq--;
        diff.insert((*s.begin()) - x);
        s.insert(x);
    } else {
        pq--;
        int p = *pp, q = *pq;
        // cout << p << " " << q << endl;
        diff.erase(diff.find(p-q));
        // cout << "euy" << endl;
        diff.insert(p-x);
        diff.insert(x-q);
        s.insert(x);
    }
}

void del(int x) {
    if (s.size() == 1) {
        s.erase(s.begin());
    } else if (s.size() == 2) {
        s.erase(s.find(x));
        diff.erase(diff.find(*diff.begin()));
    } else {
        auto pp = s.upper_bound(x), pq = (s.lower_bound(x));
        if (pp == s.end()) {
            s.erase(s.find(x));
            diff.erase(diff.find(x-(*s.rbegin())));
        } else if (pq == s.begin()) {
            pq--;
            s.erase(s.find(x));
            diff.erase(diff.find((*s.begin())-x));
        } else {
            pq--;
            diff.erase(diff.find(*pp-x));
            diff.erase(diff.find(x-*pq));
            diff.insert(*pp-*pq);
            s.erase(x);
        }
    }
}

int main () {
    //clock_t start = clock();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        ins(x);
    }
    if (diff.empty()) cout << 0 << "\n";
    else cout << (*s.rbegin()) - (*s.begin()) - (*diff.rbegin()) << "\n";
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            ins(x);
        } else {
            del(x);
        }
        // for (auto y : s) cout << y << " ";
        // cout << endl;
        // for (auto y : diff) cout << y << " ";
        // cout << endl;
        if (diff.empty()) cout << 0 << "\n";
        else cout << (*s.rbegin()) - (*s.begin()) - (*diff.rbegin()) << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
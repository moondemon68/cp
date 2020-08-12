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
    int a[100005];
    memset (a,0,sizeof(a));
    set<int> s,r,t,u;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        a[x]++;
        if (a[x] == 2) r.insert(x);
        if (a[x] == 4) s.insert(x);
        if (a[x] == 6) t.insert(x);
        if (a[x] == 8) u.insert(x);
    }
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == '+') {
            a[x]++;
            if (a[x] == 2) r.insert(x);
            if (a[x] == 4) s.insert(x);
            if (a[x] == 6) t.insert(x);
            if (a[x] == 8) u.insert(x);
        } else {
            a[x]--;
            if (a[x] == 1) r.erase(r.find(x));
            if (a[x] == 3) s.erase(s.find(x));
            if (a[x] == 5) t.erase(t.find(x));
            if (a[x] == 7) u.erase(u.find(x));
        }
        bool y = 0;
        if (u.size() >= 1 || s.size() >= 2) y = 1;  // 2 square
        else if (t.size() >= 1 && r.size() >= 2) y = 1; // 1 square + 1/2 rec  + 1/2 rec
        else if (s.size() >= 1 && r.size() >= 3) y = 1; // 1 square + 2 * 1/2 rec

        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
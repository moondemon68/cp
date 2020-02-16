#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool same(string a, string b) {
    string c = b;
    reverse(c.begin(), c.end());
    for (int i=0;i<a.size();i++) {
        if (a[i] != c[i]) return 0;
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    string a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    deque<int> d;
    bool done[n+5];
    memset (done,0,sizeof(done));
    // for (int i=1;i<=n;i++) {
    //     if (same(a[i], a[i])) {
    //         done[i] = 1;
    //         d.pb(i);
    //     }
    // }
    d.pb(0);
    for (int i=1;i<=n;i++) {
        if (done[i]) continue;
        for (int j=i+1;j<=n;j++) {
            if (done[j]) continue;
            if (same(a[i], a[j])) {
                done[i] = 1;
                done[j] = 1;
                d.push_front(i);
                d.push_back(j);
            }
        }
    }
    int x = -1;
    for (int i=1;i<=n;i++) {
        if (!done[i] && same(a[i], a[i])) {
            x = i;
            break;
        }
    }
    for (int i=0;i<d.size();i++) {
        if (d[i] == 0 && x != -1) d[i] = x;
    }
    string s = "";
    for (int i=0;i<d.size();i++) {
        if (d[i] != 0) s += a[d[i]];
    }
    cout << s.size() << endl;
    cout << s << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int a[100];
    int n = 3;
    for (int i=1;i<=6;i++) a[i] = i;
    set<vector<int>> s;
    do {
        int l[100], r[100];
        l[1] = a[1];
        l[2] = a[2];
        l[3] = a[3];
        r[1] = a[4];
        r[2] = a[5];
        r[3] = a[6];
        vector<int> v;
        int pl = 1, pr = 1;
        while (pl <= n && pr <= n) {
            if (l[pl] < r[pl]) {
                v.pb(l[pl]);
                pl++;
            } else {
                v.pb(r[pr]);
                pr++;
            }
        }
        while (pl <= n) {
            v.pb(l[pl]);
            pl++;
        }
        while (pr <= n) {
            v.pb(r[pr]);
            pr++;
        }
        s.insert(v);
    } while (next_permutation(a+1,a+7));
    for (auto x : s) {
        for (auto p : x) {
            cout << p;
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
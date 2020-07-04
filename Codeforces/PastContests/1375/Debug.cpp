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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int q;
    cin >> q;
    while (q--) {
        set<int> s;
        for (int i=1;i<=n;i++) s.insert(a[i]);
        int mex = 0;
        while (s.find(mex) != s.end()) mex++;
        int x;
        cin >> x;
        a[x] = mex;
        for (int i=1;i<=n;i++) cout << a[i] << " ";
        cout << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    vector<int> a[10005],b[10005];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int x;
            cin >> x;
            a[i+j].pb(x);
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int x;
            cin >> x;
            b[i+j].pb(x);
        }
    }
    for (int i=2;i<=n+m;i++) {
        sort (a[i].begin(),a[i].end());
        sort (b[i].begin(),b[i].end());
        if (a[i]!=b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
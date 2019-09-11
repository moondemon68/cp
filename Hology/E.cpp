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
    int n,k;
    cin >> n >> k;
    bool a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    if (!a[1]) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        if (a[k]) {
            cout << "YES" << endl;
            return 0;
        }
        bool d[n+5];
        memset (d,0,sizeof(d));
        for (int i=1;i<=n;i++) if (a[i]&&b[i]) d[i]=1;
        if (!b[k]) {
            cout << "NO" << endl;
            return 0;
        }
        for (int i=k;i<=n;i++) {
            if (d[i]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

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
    int n,m,q;
    cin >> n >> m >> q;
    int a[105];
    memset (a,0,sizeof(a));
    if (n<m) {
        for (int i=1;i<=n;i++) {
            cout << "? 1 " << i << endl;
            int x;
            cin >> x;
            if (x!=1) {
                cout << "! " << i << endl;
                return 0;
            }
            int p;
            for (int j=1;j<=x;j++) {
                cin >> p;
                a[p]++;
            }
        }
        for (int i=n+1;i<=n+m;i++) {
            if (a[i]!=1) {
                cout << "! " << i << endl;
                return 0;
            }
        }
    } else {
        for (int i=1;i<=m;i++) {
            cout << "? 1 " << n+i << endl;
            int x;
            cin >> x;
            if (x!=1) {
                cout << "! " << n+i << endl;
                return 0;
            }
            int p;
            for (int j=1;j<=x;j++) {
                cin >> p;
                a[p]++;
            }
        }
        for (int i=1;i<=n;i++) {
            if (a[i]!=1) {
                cout << "! " << i << endl;
                return 0;
            }
        }
    }
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
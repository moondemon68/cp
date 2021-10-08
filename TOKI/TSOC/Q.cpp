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
    int n,k;
    cin >> n >> k;
    if (n%2 == 1) {
        cout << "First" << endl;
        bool a[n+5];
        memset(a,0,sizeof(a));
        while (1) {
            int x = 0;
            for (int i=1;i<=n;i++) {
                if (!a[i]) x = i;
            }
            cout << x << endl;
            a[x] = 1;
            int y;
            cin >> y;
            a[abs(y)] = 1;
            if (y == 0) break;
        }
        int x = 0;
        for (int i=1;i<=n;i++) {
            if (!a[i]) x = i;
        }
        cout << x << endl;
        int y ;
        cin >> y;
    } else {
        cout << "Second" << endl;
        bool a[n+5];
        memset(a,0,sizeof(a));
        while (1) {
            int y;
            cin >> y;
            a[abs(y)] = 1;
            if (y == 0) break;
            int x = 0;
            for (int i=1;i<=n;i++) {
                if (!a[i]) x = i;
            }
            cout << x << endl;
            a[x] = 1;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
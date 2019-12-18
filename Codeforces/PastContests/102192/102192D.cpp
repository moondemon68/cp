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
    int tc;
    cin >> tc;
    while (tc--) {
        int x,y;
        cin >> x >> y;
        if (x%2==0&&y%2==0) {
            if (x<y) {
                for (int i=1;i<=x;i++) {
                    for (int j=1;j<=y;j++) {
                        if (i%2==1) cout << '('; else cout << ')';
                    }
                    cout << endl;
                }
            } else {
                for (int i=1;i<=x;i++) {
                    for (int j=1;j<=y;j++) {
                        if (j%2==1) cout << '('; else cout << ')';
                    }
                    cout << endl;
                }
            }
        } else if (x%2==0) {
            for (int i=1;i<=x;i++) {
                for (int j=1;j<=y;j++) {
                    if (i%2==1) cout << '('; else cout << ')';
                }
                cout << endl;
            }
        } else if (y%2==0) {
            for (int i=1;i<=x;i++) {
                for (int j=1;j<=y;j++) {
                    if (j%2==1) cout << '('; else cout << ')';
                }
                cout << endl;
            }
        } else {
            for (int i=1;i<=x;i++) {
                for (int j=1;j<=y;j++) {
                    if (j%2==1) cout << '('; else cout << ')';
                }
                cout << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
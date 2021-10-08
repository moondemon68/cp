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
    ofstream cout("astar.out");
    bool y = 1;
    int n = 500;
    cout << n << endl;
    for (int i=1;i<=n;i++) {
        if (i%2 == 1) {
            for (int j=1;j<=n;j++) cout << 1 << " ";
        } else {
            if (y) {
                for (int j=1;j<n;j++) cout << 999999999 << " ";
                cout << 1 << " ";
            } else {
                cout << 1 << " ";
                for (int j=1;j<n;j++) cout << 999999999 << " ";
            }
            y = !y;
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cout << "(1/" << i+j-1 << "*x_" << j << ")";
            if (j<n) cout << "+"; else if (j==n) cout << "=";
        }
        cout << (i==1?1:0) << "; ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
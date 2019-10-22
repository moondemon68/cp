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
    if (n%4==0) {
        cout << "YES" << endl;
        cout << "1 * 2 = 2" << endl;
        cout << "3 * 2 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
        for (int i=1;i<n/4;i++) {
            cout << 4*i+1 << " - " << 4*i+2 << " = -1" << endl;
            cout << 4*i+4 << " - " << 4*i+3 << " = 1" << endl;
            cout << 1 << " + " << -1 << " = 0" << endl;
            cout << 24 << " + " << 0 << " = 24" << endl;
        }
        return 0;
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
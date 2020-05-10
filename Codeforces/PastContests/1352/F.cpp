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
        int a,b,c;
        cin >> a >> b >> c;
        if (b > 0) {
            for (int i=1;i<=c+1;i++) cout << 1;
            for (int i=1;i<=a+1;i++) cout << 0;
            for (int i=1;i<b;i++) cout << i%2;
        } else {
            if (a > 0) {
                for (int i=1;i<=a+1;i++) cout << 0;
            } else {
                for (int i=1;i<=c+1;i++) cout << 1;
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    LL p[40];
    memset (p,0,sizeof(p));
    p[0] = 1;
    for (int i=1;i<=30;i++) p[i] = p[i-1] * 2;
    int tc;
    cin >> tc;
    while (tc--) {
        LL x;
        cin >> x;
        LL v = 0;
        for (int i=0;i<=31;i++) {
            v += p[i];
            if (i > 0 && x%v == 0) {
                cout << x/v << endl;
                break;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
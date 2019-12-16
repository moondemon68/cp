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
        LL x;
        cin >> x;
        LL cnt=1;
        for (LL i=2;i*i<=x;i++) {
            if (x%i==0) {
                LL p = 0;
                while (x%i==0) {
                    p++;
                    x/=i;
                }
                cnt *= 2*p+1;
            }
        }
        if (x>1) cnt *= 2*1+1;
        cout << cnt/2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
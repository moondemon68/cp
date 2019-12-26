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
    int n;
    cin >> n;
    LL b=0, w=0;
    for (int i=1;i<=n;i++) {
        LL x;
        cin >> x;
        if (i%2 == 0) {
            b += x/2;
            w += x/2;
            if (x%2 == 1) w++;
        } else {
            b += x/2;
            w += x/2;
            if (x%2 == 1) b++;
        }
    }
    cout << min(b,w) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
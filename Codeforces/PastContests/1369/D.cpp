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

LL a[2000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    memset (a,0,sizeof(a));
    a[1] = 0;
    a[2] = 0;
    a[3] = 4;
    a[4] = 4;
    a[5] = 12;
    for (int i=6;i<=2000000;i++) {
        a[i] = a[i-1] + 2*a[i-2];
        a[i] %= MOD;
        if (i % 3 == 0) {
            a[i]+=4;
            a[i] %= MOD;
        }
    }
    while (tc--) {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
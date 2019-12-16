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

LL p[1000005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,a,b;
    cin >> n >> a >> b;
    if ((a!=b&&n/b==n/a&&n%b!=0) || (a==b&&n%a!=0)) {
        cout << "NO" << endl;
        return 0;
    }
    LL tot = 0;
    LL m;
    for (int i=1;i*b<=n;i++) {
        p[i]=b;
        tot+=b;
        m = i;
    }
    if (tot != n) {
        m++;
        p[m]=b;
        tot += b;
    }
    cout << "YES" << endl;
    LL rem = n-tot;
    //cout << rem << endl;
    for (int i=1;i<=m;i++) {
        if (rem>a-b && rem < 0) {
            p[i]-=rem*-1;
            rem=0;
        } else if (rem < 0) {
            p[i]=a;
            rem+=b-a;
        }
        if (rem == 0) break;
    }
    //cout << rem << endl;
    for (int i=1;i<=m;i++) cout << p[i] << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
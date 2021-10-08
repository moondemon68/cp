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
    // ofstream cout("empat_7.in");
    // LL a = 0;
    LL b = 993807990;
    // LL c = 0;
    // LL d = 0;
    LL n = 987654321123456789;
    LL ans = n;
    LL maxd = ceil(sqrt(n));
    for (LL a=0;a*a<=maxd;a++) {
    // for (LL b=0;b*b<=n;b++) {
    for (LL c=0;c*c<=maxd;c++) {
    for (LL d=0;d*d<=maxd;d++) {
        if ((a * a + b * b + c * c + d * d) == n) {
            cout << a << " " << b << " " << c << " " << d << endl;
            return 0;
        }
        if (abs((a * a + b * b + c * c + d * d) - n) < ans) {
            ans = abs((a * a + b * b + c * c + d * d) - n);
            cout << ans << " " << a << " " << b << " " << c << " " << d << endl;
        }
    }
    }
    // }
    }
    // cout << a * a + b * b + c * c + d * d << endl;
    // cout << (n-(a * a + b * b + c * c + d * d)) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
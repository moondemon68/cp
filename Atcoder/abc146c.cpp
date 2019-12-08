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
    LL p[15];
    p[0]=1;
    for (int i=1;i<=12;i++) p[i] = p[i-1]*10;
    LL a,b,x;
    cin >> a >> b >> x;
    LL ans = 0;
    for (int i=1;i<=9;i++) {
        LL left = x-i*b;
        LL cand = left/a;
        if (cand > p[i]-1) {
            cand = p[i]-1;
        }
        ans=max(ans, cand);
    }
    if (a * 1000000000 + b * 10 <= x) ans = 1000000000;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
// #pragma GCC diagnostic error "-fwhole-program"
// #pragma GCC diagnostic error "-fcse-skip-blocks"
// #pragma GCC diagnostic error "-funsafe-loop-optimizations"
// #pragma GCC diagnostic error "-std=c++14"
// #pragma GCC target ("string"...)
#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m,k;
    cin >> n >> m >> k;
    LL a[n+5];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=1;i<=n;i++) a[i]+=a[i-1];
    LL ans=0;
    LL p[n+5];
    memset (p,0,sizeof(p));
    for (LL l=1;l<=n;l++) {
        LL maxi=0;
        for (LL i=1;i<=n-l+1;i++) {
            maxi=max(maxi,a[i+l-1]-a[i-1]);
        }
        p[l]=max(p[l],maxi);
    }
    for (LL i=1;i<=n;i++) {
        //cout << p[i] << endl;
        ans=max(ans,p[i]-(i+m-1)/m*k);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
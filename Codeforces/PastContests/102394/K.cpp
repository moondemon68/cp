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
    LL tc;
    scanf("%I64d",&tc);
    while (tc--) {
        LL n;
        LL k;
        scanf("%I64d%I64d",&n,&k);
        LL a[n+5];
        LL tot = 0;
        for (int i=1;i<=n;i++) {
            scanf("%I64d",&a[i]);
            tot += a[i];
        }
        for (int i=1;i<=n;i++) {
            printf("%.6f ",a[i] + (double)a[i] * k / tot);
        }
        printf("\n");
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
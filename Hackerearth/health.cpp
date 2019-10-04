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
    int tc;
    scanf("%d",&tc);
    while (tc--) {
        int n,m;
        scanf("%d %d",&n,&m);
        int a[n+5];
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int b[m+5];
        for (int i=1;i<=m;i++) scanf("%d",&b[i]);
        b[0]=0;
        int ans[n+5];
        memset (ans,-1,sizeof(ans));
        for (int i=1;i<=m;i++) {
            for (int j=i;j<=n;j+=i) {
                if (a[j]<=b[i] && ans[j]==-1) {
                    ans[j]=i;
                }
            }
        }
        for (int i=1;i<=n;i++) {
            printf("%d\n",ans[i]);
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
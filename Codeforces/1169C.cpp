#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int n,m;

bool check(int a[],int x) {
    int p=0;
    for (int i=1;i<=n;i++) {
        if ((a[i]<=p&&p<=a[i]+x)||(a[i]<=p+m&&p+m<=a[i]+x)) continue;
        if (a[i]>=p) {
            p=a[i];
        } else {
            return 0;
        }
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int l=0,r=m,ans=0;
    while (l<=r) {
        int mid=(l+r)/2;
        if (check(a,mid)) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
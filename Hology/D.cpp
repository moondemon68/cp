#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int a[300005],n,k;

bool cek(int x) {
    int b[300005];
    int last=0;
    memset (b,0,sizeof(b));
    for (int i=k;i<=n;i++) {
        if (a[i]-a[b[i-k]+1]<=x) {
            b[i]=i;
            last=i;
        } else {
            b[i]=last;
        }
    }
    return b[n]==n;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    a[0]=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    int l=0,h=a[n]-a[1],ans=-1;
    while (l<=h) {
        int m=(l+h)/2;
        if (cek(m)) {
            ans=m;
            h=m-1;
        } else {
            l=m+1;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
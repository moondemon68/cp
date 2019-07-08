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
    int n,d;
    cin >> n >> d;
    int a[n+5];
    for (int i=1;i<=n;i++) {
        int x,y;
        cin >> x >> y;
        a[i]=x+y;
    }
    sort (a+1,a+n+1);
    int ans=0;
    for (int i=1;i<=n;i++) {
        int l=i,h=n,p=i;
        while (l<=h) {
            int m=(l+h)/2;
            if (a[m]-a[i]<=2*d) {
                p=m;
                l=m+1;
            } else h=m-1;
        }
        ans=max(ans,p-i+1);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
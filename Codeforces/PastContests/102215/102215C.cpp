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
    LL p,n;
    cin >> p >> n;
    bool a[p+5];
    memset (a,0,sizeof(a));
    a[0]=1;
    LL x=0;
    for (LL i=1;i<=min(4*p,n);i++) {
        x+=i;
        x%=p;
        a[x]=1;
    }
    int ans=0;
    for (int i=0;i<p;i++) ans+=a[i];
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
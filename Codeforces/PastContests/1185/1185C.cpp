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
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int t[105],tot=0;
    memset (t,0,sizeof(t));
    for (int i=1;i<=n;i++) {
        tot+=a[i];
        int d=tot-m,ans=0,p=100;
        while (d>0&&p>0) {
            if (t[p]*p>=d) {
                if (d%p>0) ans++; 
                ans+=d/p;
                d=0;
            } else {
                ans+=t[p];
                d-=t[p]*p;
            }
            p--;
        }
        cout << ans << " ";
        t[a[i]]++;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
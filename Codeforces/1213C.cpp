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
    int tc;
    cin >> tc;
    while (tc--) {
        LL n,m;
        cin >> n >> m;
        vector<LL> a;
        LL s=0;
        for (int i=0;i<10;i++) {
            s+=(m*i)%10;
            a.pb((m*i)%10);
        }
        LL p=n/m;
        LL ans=0;
        ans+=(p/10)*s;
        for (int i=0;i<=(p%10);i++) ans+=a[i];
        cout << ans << endl;
    } 
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
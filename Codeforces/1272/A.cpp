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
        int a,b,c;
        cin >> a >> b >> c;
        int ans=abs(c-b) + abs(b-a) + abs(c-a);
        for (int i=-1;i<=1;i++) {
            for (int j=-1;j<=1;j++) {
                for (int k=-1;k<=1;k++) {
                    int na=a+i, nb=b+j, nc=c+k;
                    ans = min(ans,abs(nc-nb) + abs(nb-na) + abs(nc-na));
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
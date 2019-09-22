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
        LL x,y;
        cin >> x >> y;
        LL ans=max(x,y) * max(x,y);
        if (max(x,y)%2==0) {
            if (x>=y) ans-=y-1;
            else {
                ans-=y-1;
                ans-=y-x;
            } 
        } else {
            if (y>=x) ans-=x-1;
            else {
                ans-=x-1;
                ans-=x-y;
            } 
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
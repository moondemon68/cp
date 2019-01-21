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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        LL p,r,f;
        cin >> p >> r >> f;
        int ans=0;
        while (p<=f) {
            ans++;
            p*=r;
        }
        cout << ans << endl;
    }
    return 0;
}

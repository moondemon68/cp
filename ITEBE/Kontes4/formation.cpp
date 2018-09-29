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
    LL n,m;
    cin >> n >> m;
    LL g=0,ans=0;
    for (int i=1;i*i<=min(n,m);i++) {
      if (n%i==0&&m%i==0) {
        g=i;
        ans=max(ans,2*g+n/g+m/g);
      }
    }
    cout << ans << endl;
    return 0;
}

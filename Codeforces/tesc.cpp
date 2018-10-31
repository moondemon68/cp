#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n,k;
int a[105],dp[105][105],dig[105];

int solve(int )

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
      cin >> n >> k;
      for (int i=1;i<=n;i++) cin >> a[i];
      memset (dig,0,sizeof(dig));
      memset (dp,0,sizeof(dp));
      for (int i=1;i<=n;i++) {
        while (a[i]>0) {
          dig[i]+=a[i]%10;
          a[i]/=10;
        }
        cout << dig[i] << endl;
      }

    }
    return 0;
}

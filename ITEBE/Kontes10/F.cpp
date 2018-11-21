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
      int n;
      cin >> n;
      int x=-1;
      int ans[20005];
      memset (ans,0,sizeof(ans));
      for (int i=1;i<=n;i++) {
        int rem=n-i+1;
        for (int j=0;j<=i%rem;j++) {
          x++;
          x%=n;
          if (ans[x]!=0) {
            j--;
          }
        }
        ans[x]=i;
      }
      for (int i=0;i<n;i++) cout << ans[i] << " ";
      cout << "\n";
    }
    return 0;
}

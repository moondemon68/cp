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
      int ans[n+5];
      if (n%3==2) {
        int a[2*n+5];
        for (int i=1;i<=n-2;i++) {
          cout << "1 " << i << " " << i+1 << " " << i+2 << endl;
          cin >> a[i];
        }
        cout << "1 1 " << n-1 << " " << n << endl;
        cin >> a[n-1];
        cout << "1 1 " << 2 << " " << n << endl;
        cin >> a[n];
        for (int i=1;i<=n;i++) {
          a[n+i]=a[i];
        }
        memset (ans,0,sizeof(ans));
        int all=0;
        for (int i=1;i<=n;i++) all^=a[i];
        for (int i=1;i<=n;i++) {
          ans[i]=all;
          int x=i;
          for (int j=1;j<=(n+2)/3;j++) {
            ans[i]^=a[x];
            x+=3;
          }
        }
      } else if (n%3==0) {
        
      } else if (n%3==1) {

      }

      //OUTPUT
      cout << 2 << " ";
      for (int i=1;i<=n;i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
      int verdict;
      cin >> verdict;
    }
    return 0;
}

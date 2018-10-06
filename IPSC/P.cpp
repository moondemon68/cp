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
    //freopen ("P1.in","r",stdin);
    freopen ("P2.out","w",stdout);
    int tc;
    cin >> tc;
    while (tc--) {
      int n;
      cin >> n;
      int cnt=1;
      while (sqrt(cnt*n)*sqrt(cnt*n)!=(cnt*n)) {
        cnt++;
      }
      int p=0;
      cout << sqrt(cnt*n) << endl;
      for (int i=1;i<=n;i++) {
        for (int j=1;j<=cnt;j++) {
          char a=i-1+'a';
          cout << a;
          p++;
          if (p==sqrt(cnt*n)) {
            p=0;
            cout << endl;
          }
        }
      }
      cout << endl;
    }
    return 0;
}

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
    freopen ("a2.in","r",stdin);
    freopen ("a2.out","w",stdout);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      int n;
      cin >> n;
      for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if (i==n) {
          cout << "1";
          break;
        }
        for (int j=2;j>=0;j--) {
          if (x>=pow(10,j)) {
            cout << pow(10,j) << " ";
            break;
          }
        }
      }
      cout << endl;
    }
    return 0;
}

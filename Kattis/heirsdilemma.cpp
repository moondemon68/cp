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
    int l,r;
    cin >> l >> r;
    int ans=0;
    for (int i=l;i<=r;i++) {
      int x=i;
      int y=1;
      set<int> a;
      while (x>0) {
        if (x%10==0) {
          y=0;
          break;
        }
        if (i%(x%10)!=0) {
          y=0;
          break;
        }
        a.insert(x%10);
        x/=10;
      }
      if (a.size()!=6) y=0;
      ans+=y;
    }
    cout << ans << endl;
    return 0;
}

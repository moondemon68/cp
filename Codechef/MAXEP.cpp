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
    int n,c;
    cin >> n >> c;
    int l=0,h=n,ans=1;
    int ret[150005];
    memset (ret,-1,sizeof(ret));
    while (l<h) {
      int add=1,rep=0,safeadd=1;
      while (rep!=1&&l+add<=h) {
        if (ret[l+add]==-1) {
          cout << "1 " << l+add << endl;
          cin >> rep;
          if (rep==1) cout << 2 << endl;
          ret[l+add]=rep;
        } else rep=ret[l+add];
        if (rep==0) {
          safeadd=add;
          add*=2;
        }
        else {
          break;
        }
      }
      if (rep==0) l+=safeadd; else {
        l+=safeadd;
        h=l+add/2;
      }
    }
    cout << "3 " << l << endl;
    return 0;
}

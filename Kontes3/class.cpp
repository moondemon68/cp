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
    int tc;
    scanf("%d",&tc);
    map<int,int> m;
    for (int t=1;t<=tc;t++) {
      int k;
      scanf("%d",&k);
      bool y=0;
      if (m[k]!=0) {
        printf("%d\n",m[k]);
        y=1;
      }
      for (int i=k;i>=0;i--) {
        if (y) break;
        bool p=1;
        for (int j=2;j*j<=i;j++) {
          if (i%j==0) {
            p=0;
            break;
          }
        }
        if (p) {
          m[k]=k-i;
          printf("%d\n",m[k]);
          break;
        }
      }
    }
    return 0;
}

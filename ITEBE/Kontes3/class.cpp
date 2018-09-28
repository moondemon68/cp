#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bitset<100000005> prima;

void sieve(int n) {
  prima.set();    //ubah semua jadi 1
  prima[0]=0;
  prima[1]=0;
  for (int i=2;i*i<=n;i++) {
      if (prima[i]) {
        for (int j=i*i;j<=n;j+=i) {
          prima[j]=0;
        }
      }
  }
}

int main () {
    sieve(100000000);
    int tc;
    scanf("%d",&tc);
    for (int t=1;t<=tc;t++) {
      int x;
      scanf("%d",&x);
      for (int i=x;i>=1;i--) {
        if (prima[i]) {
          printf("%d\n",x-i);
          break;
        }
      }
    }
}

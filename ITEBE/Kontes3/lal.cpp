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
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
      long long q;
      scanf("%lld",&q);

      printf("%lld\n",(q/3)*2+(q%3!=0));
    }
    return 0;
}

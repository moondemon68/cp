#include <iostream>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
 
using namespace std;
 
LL poww(LL a, LL n, LL m) {
  LL res=1;
  a%=m;
  while (n>0) {
    if (n%2==1) res=(res*a)%m;
    a=(a*a)%m;
    n/=2;
  }
  return res;
}
 
bool test(LL d, LL n,int k) {
  LL a;
  if (k==1) a=2;
  else if (k==2) a=3;
  else if (k==3) a=5;
  else if (k==4) a=7;
  LL x=poww(a,d,n);
  if (x==1||x==n-1) return 1;
  while (d!=n-1) {
    x=(x*x)%n;
    d*=2;
    if (x==1) return 0;
    if (x==n-1) return 1;
  }
  return 0;
}
 
bool prima(LL n, LL k) {
  if (n==1||n==4||n==6||n==8||n==9) return 0;
  if (n==2||n==3||n==5||n==7) return 1;
  LL d=n-1;
  while (d%2==0) {
    d/=2;
  }
  for (int i=1;i<=k;i++) {
    if (!test(d,n,i)) return 0;
  }
  return 1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    scanf("%d",&tc);
    for (int t=1;t<=tc;t++) {
      LL x;
      scanf("%lld",&x);
      LL ans=0;
      for (LL i=x;i>=1;i--) {
      	if (i>2&&i%2==0) continue;
        if (prima(i,4)) {
          ans=i;
          break;
        }
      }
      printf("%lld\n",x-ans);
    }
    return 0;
}
 
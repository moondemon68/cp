#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL gcd(LL a,LL b, LL &x, LL &y) {
  if (a==0) {
    x=0;
    y=1;
    return b;
  }
  LL x1,y1;
  LL d=gcd(b%a,a,x1,y1);
  x=y1-(b/a)*x1;
  y=x1;
  return d;
}

LL inverse_modulo(LL a,LL m) {
  LL x,y;
  LL ans=gcd(a,m,x,y);
  return (x%m + m)%m;
}

int main () {
    LL d[100005];
    for (LL i=1;i<=100000;i++) d[i]=1;
    for (LL i=2;i<=100000;i++) {
      for (LL j=i;j<=100000;j+=i) {
        d[j]++;
      }
    }
    LL n;
    scanf("%lld",&n);

    LL a[n+5];
    for (LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    LL ans=0;
    for (int i=1;i<=n;i++) {
      LL tt=1;
      tt*=a[i]*(n-d[i]);
      tt%=MOD;
      tt*=inverse_modulo(d[i]+1,MOD);
      tt%=MOD;
      cout << tt << endl;
      ans+=tt;
      ans%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}

/* ALGO FAKTORISASI PRIMA
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

bool prima[100005];
vector<LL> p;

void sieve(LL n) {
  memset (prima,1,sizeof(prima));
  prima[0]=0;
  prima[1]=0;
  for (LL i=2;i*i<=n;i++) {
    for (LL j=i*i;j<=n;j+=i) {
      prima[j]=0;
    }
  }
  for (LL i=2;i<=n;i++) {
    if (prima[i]) p.pb(i);
  }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(100000);
    LL n,m,k;
    cin >> n >> k >> m;
    LL cnt[9595];
    memset (cnt,0,sizeof(cnt));
    vector<LL> pro;
    for (LL i=n;i>n-k;i--) {
      LL x=i;
      for (LL j=0;j<p.size();j++) {
        while (x%p[j]==0) {
          cnt[j]++;
          x/=p[j];
        }
      }
      pro.pb(x);
    }
    for (LL i=k;i>0;i--) {
      LL x=i;
      for (LL j=0;j<p.size();j++) {
        while (x%p[j]==0) {
          cnt[j]--;
          x/=p[j];
        }
      }
    }
    LL ans=1;
    for (LL i=0;i<p.size();i++) {
      while (cnt[i]>0) {
        cnt[i]--;
        ans*=p[i];
        ans%=m;
      }
    }
    for (LL i=0;i<pro.size();i++) {
      ans*=pro[i];
      ans%=m;
    }
    cout << ans << endl;
    return 0;
}
*/
// ALGO EXTENDED EUCLID
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
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
    LL n,k,m;
    cin >> n >> k >> m;
    LL up=1;
    for (LL i=n;i>n-k;i--) {
      up*=i;
      up%=m;
    }
    //cout << up << endl;
    LL down=1;
    for (LL i=1;i<=k;i++) {
      down*=i;
      down%=m;
    }
    //cout << down << endl;
    LL im=inverse_modulo(down,m);
    if (im<0) im+=m;
    //cout << im << endl;
    cout << ((up%m)*(im%m))%m << endl;
    return 0;
}

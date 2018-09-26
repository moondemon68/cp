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

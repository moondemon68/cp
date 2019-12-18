#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

bool cmp (pii a,pii b){
  return a.se<b.se;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,r,avg;
    cin >> n >> r >> avg;
    pii a[100005];
    LL sum=0;
    avg*=n;
    for (int i=1;i<=n;i++) {
      cin >> a[i].fi >> a[i].se;
      sum+=a[i].fi;
    }
    sort (a+1,a+n+1,cmp);
    LL ans=0;
    int i=1;
    while (sum<avg) {
      ans+=(r-a[i].fi)*a[i].se;
      sum+=(r-a[i].fi);
      if (sum>avg) {
        ans-=(sum-avg)*a[i].se;
      }
      i++;
    }
    cout << ans << endl;
    return 0;
}

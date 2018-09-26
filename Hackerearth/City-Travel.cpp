#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL s,x,n;
    cin >> s >> x >> n;
    LL ans=0;
    pair<LL,LL> a[1005];
    a[0]=mp(0,0);
    for (LL i=1;i<=n;i++) {
      cin >> a[i].fi >> a[i].se;
    }
    sort (a+1,a+n+1);
    for (LL i=1;i<=n;i++) {
      if (s>0) {
        s-=(a[i].fi-1-ans)*x;
        ans+=(a[i].fi-1-ans);
        //cout<< s << endl;
        if (s<0) {
          while (s<0) {
            s+=x;
            ans--;
          }
          break;
        }
        if (s>0) {
          s-=a[i].se;
          ans++;
        }
      }
      //cout << ans << " " << s << endl;
    }
    if (s>0) {
      ans+=(s/x+(s%x>0));
    }
    cout << ans << endl;
    return 0;
}

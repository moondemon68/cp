#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

LL cnt[1000005];

int main () {
    LL tc;
    cin >> tc;
    while (tc--) {
      LL n;
      cin >> n;
      memset (cnt,0,sizeof(cnt));
      vector<LL> a;
      for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        cnt[x]++;
        a.pb(x);
      }
      sort (a.begin(),a.end());
      //reverse(a.begin(),a.end());
      LL ans=1;
      for (int i=0;i<a.size();i+=2) {
        if (a[i]==a[i+1]) {
          LL d=(cnt[a[i]]-1);
          d%=MOD;
          ans*=d;
          ans%=MOD;
          //cout << cnt[a[i]] << " " << 2 << endl;
          cnt[a[i]]-=2;
        } else {
          ans*=cnt[a[i]];
          ans%=MOD;
          //cout << cnt[a[i]] << " " << 1 << endl;
          cnt[a[i]]--;
          ans*=cnt[a[i+1]];
          ans%=MOD;
          //cout << cnt[a[i+1]] << " " << 1 << endl;
          cnt[a[i+1]]--;
        }
      }
      cout << ans << endl;
      //cout << "END OF TC" << endl;
    }
    return 0;
}

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
    LL tc;
    cin >> tc;
    while (tc--) {
      LL n;
      cin >> n;
      queue<LL> a;
      for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        a.push(x);
      }
      LL t=a.front();
      a.pop();
      LL ans=0;
      while (!a.empty()) {
        LL x=t;
        while (x>0&&!a.empty()) {
          x--;
          t+=a.front();
          a.pop();
        }
        ans++;
      }
      cout << ans << endl;
    }
    return 0;
}

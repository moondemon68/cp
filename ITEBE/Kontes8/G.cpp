#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool cmp(pii a,pii b) {
  return a.se<b.se;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (1>0) {
      cin >> n;
      if (n==0) return 0;
      pii c[1005];
      for (int i=1;i<=n;i++) cin >> c[i].fi >> c[i].se;
      sort (c+1,c+n+1,cmp);
      float ans=0;
      for (int i=1;i<n;i++) {
        ans+=sqrt((c[i+1].fi-c[i].fi)*(c[i+1].fi-c[i].fi)+(c[i+1].se-c[i].se)*(c[i+1].se-c[i].se));
      }
      cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("A-large.in", "r", stdin);
    freopen("A-largeans.out", "w", stdout);    
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      int n,k;
      cin >> n >> k;
      LL ans=1;
      for (int i=1;i<=n;i++) ans*=2;
      bool a[105];
      string s[105];
      memset (a,0,sizeof(a));
      for (int i=1;i<=k;i++) {
        cin >> s[i];
      }
      for (int i=1;i<=k;i++) {
        for (int j=1;j<=k;j++) {
          if (i==j) continue;
          bool y=1;
          for (int p=0;p<s[i].size();p++) {
            if (s[i][p]!=s[j][p]) y=0;
          }
          if (y) {
            a[j]=1;
          }
        }
      }
      for (int i=1;i<=k;i++) {
        if (a[i]) continue;
        LL num=1;
        for (int j=1;j<=n-s[i].size();j++) num*=2;
        ans-=num;
      }
      cout << "Case #" << t <<": " << ans << endl;
    }
    return 0;
}

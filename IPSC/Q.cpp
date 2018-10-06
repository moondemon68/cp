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
    //freopen ("q1.in","r",stdin);
    //freopen ("q1.out","w",stdout);
    int tc;
    cin >> tc;
    while (tc--) {
      int n;
      cin >> n;
      map<string,int> m;
      int ans=-1;
      vector<int> g;
      for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        bool y=1;
        for (int i=0;i<s.size();i++) {
          if (s[i]<'0'||s[i]>'9') y=0;
        }
        int x=0;
        int p=s.size()-1;
        if (y) {
          while (p>=0) {
            x+=s[p]-'0';
            x*=10;
            p--;
          }
          x/=10;
        }
        if (x>0) {
          y=1;
          for (int i=0;i<g.size();i++) {
            if (x%g[i]==0) y=0;
          }
          if (y) continue;
          else {
            ans=i;
            break;
          }
        }

        if (m[s]==0&&) {
          m[s]=i;
          g.pb(i);
        }
        else {
          if (i%m[s]!=0) {
            ans=i;
            continue;
          }
        }
      }

      cout << ans << endl;
    }
    return 0;
}

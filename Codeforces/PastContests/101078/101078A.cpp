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
    int tc;
    cin >> tc;
    while (tc--) {
      int n;
      cin >> n;
      int a[n+5],b[n+5];
      for (int i=1;i<=n;i++) cin >> a[i];
      for (int i=1;i<=n;i++) cin >> b[i];
      int s[n+5],t[n+5];
      vector<int> p;
      memset (s,0,sizeof(s));
      memset (t,0,sizeof(t));
      int x=1;
      for (int i=1;i<=n;i++) {
        s[a[i]]++;
        s[b[i]]--;
        p.pb(a[i]);
        bool y=1;
        for (int j=0;j<p.size();j++) {
          if (s[p[j]]!=0) {
            y=0;
            break;
          }
        }
        if (y) {
          cout << x << "-" << i << " ";
          p.clear();
          x=i+1;
        }
      }
      cout << endl;
    }
    return 0;
}

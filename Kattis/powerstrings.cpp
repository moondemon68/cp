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
    string s;
    while (cin >> s) {
      if (s[0]=='.') return 0;
      int ans=1;
      vector<int> f;
      for (int i=1;i*i<=s.size();i++) {
        if (s.size()%i==0) {
          f.pb(i);
          f.pb(s.size()/i);
        }
      }
      sort (f.begin(),f.end());
      reverse (f.begin(),f.end());
      for (int i=0;i<f.size();i++) {
        bool y=1;
        for (int j=0;j<s.size();j++) {
          if (s[j%f[i]]!=s[j]) {
            y=0;
            break;
          }
        }
        if (y) {
          ans=f[i];
        }
      }
      cout << s.size()/ans << endl;
    }
    return 0;
}

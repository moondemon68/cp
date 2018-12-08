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
    cin >> s;
    double ans=0;
    for (int i=0;i<s.size();i++) {
      if (s[i]=='0') continue;
      for (int j=s.size()-1;j>i;j--) {
        if (s[j]=='0') {
          swap(s[i],s[j]);
          ans+=sqrt(j-i);
          break;
        }
      }
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}

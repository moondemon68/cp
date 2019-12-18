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
    int n;
    cin >> n;
    LL l=0,h=1000000000;
    cout << (l+h)/2 << " " << (l+h)/2 << endl;
    string s;
    cin >> s;
    l=(l+h)/2;
    LL ans=l;
    for (int i=1;i<n;i++) {
      LL m=(l+h)/2;
      cout << m << " " << m << endl;
      string t;
      cin >> t;
      if (s==t) {
        l=m;
      } else {
        h=m;
      }
      ans=m;
    }
    ans=(l+h)/2;
    cout << ans << " " << ans << " " << ans+1 << " " << ans-1 << endl;
    return 0;
}

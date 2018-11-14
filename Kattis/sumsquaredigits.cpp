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
    for (int t=1;t<=tc;t++) {
      int b;
      cin >> b;
      cout << b << " ";
      cin >> b;
      int s;
      cin >> s;
      LL ans=0;
      vector<int> a;
      while (s>0) {
        a.push_back(s%b);
        s/=b;
      }
      for (int i=0;i<a.size();i++) {
        ans+=a[i]*a[i];
      }
      cout << ans << endl;
    }
    return 0;
}

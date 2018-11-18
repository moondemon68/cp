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
      string s;
      cin.ignore();
      getline(cin,s);
      cout << s << endl;
      int x;
      cin >> x;
      cin >> s;
      cout << x << " " << s << endl;
      int cnt=0;
      int ans[11];
      memset (ans,0,sizeof(ans));
      while (cnt<x) {
        cin >> s;
        if (s=="+") {
          int a,b,c;
          cin >> a >> b >> c;
          for (int i=a;i<=b;i+=c) {
            cnt++;
            int n=i;
            while (n>0) {
              ans[n%10]++;
              n/=10;
            }
          }
        } else {
          cnt++;
          for (int i=0;i<s.size();i++) {
            ans[s[i]-'0']++;
          }
        }
      }
      int total=0;
      for (int i=0;i<=9;i++) {
        cout << "Make " << ans[i] << " digit " << i << endl;
        total+=ans[i];
      }
      if (x!=1) cout << "In total " << total << " digits" << endl;
      else cout << "In total 1 digit" << endl;
    }
    return 0;
}

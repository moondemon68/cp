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
    string s;
    cin >> s;
    string ans=s;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=10;j++) {
        for (int k=0;k<n;k++) {
          if (s[k]=='9') s[k]='0'; else s[k]++;
        }
        if (s<ans) ans=s;
      }
      char tmp=s[0];
      s.erase(s.begin());
      s+=tmp;
    }
    cout << ans << endl;
    return 0;
}

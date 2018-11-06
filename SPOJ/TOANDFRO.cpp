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
    while (1>0) {
      int n;
      cin >> n;
      if (n==0) return 0;
      string s;
      cin >> s;
      int a[105][25];
      int cnt=0;
      for (int i=0;i<s.size()/n;i++) {
        if (i%2==0) {
          for (int j=0;j<n;j++) {
            a[i][j]=s[cnt];
            cnt++;
          }
        }
        else {
          for (int j=n-1;j>=0;j--) {
            a[i][j]=s[cnt];
            cnt++;
          }
        }
      }
      string ans="";
      for (int i=0;i<n;i++) {
        for (int j=0;j<s.size()/n;j++) ans+=a[j][i];
      }
      cout << ans << endl;
    }
    return 0;
}

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
    int a[15];
    memset (a,0,sizeof(a));
    for (int i=1;i<=5;i++) {
      string s;
      cin >> s;
      if (s[0]=='T') a[14]++;
      else if (s[0]=='A') a[13]++;
      else if (s[0]=='K') a[12]++;
      else if (s[0]=='Q') a[11]++;
      else if (s[0]=='J') a[10]++;
      else a[s[0]-'0']++;
    }
    int ans=0;
    for (int i=1;i<=14;i++) {
      ans=max(ans,a[i]);
    }
    cout << ans << endl;
    return 0;
}

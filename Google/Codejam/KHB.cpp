#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
int a[5000005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("B-large.in", "r", stdin);
    freopen("B-large-ans.out", "w", stdout);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      memset (a,0,sizeof(a));
      int n;
      cin >> n;
      string s;
      cin >> s;
      for (int i=1;i<=s.size();i++) {
        a[i]+=s[i-1]-'0';
        a[i]+=a[i-1];
      }
      int ans=0;
      int size=n/2+n%2;
      for (int i=0;i<=n-size;i++) {
        ans=max(ans,a[i+size]-a[i]);
      }
      cout << "Case #" << t <<": " << ans << endl;
    }
    return 0;
}

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
    int n;
    cin >> n;
    int cnt[1005];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int ans=0,ansi=0;
    for (int i=1;i<=1000;i++) {
      if (cnt[i]>0) ansi++;
      ans=max(ans,cnt[i]);
    }
    cout << ans << " " << ansi << endl;
    return 0;
}

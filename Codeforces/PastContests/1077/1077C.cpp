#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int c[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[200005];
    for (int i=1;i<=n;i++) cin >> a[i];
    memset (c,0,sizeof(c));
    LL sum=0;
    for (int i=1;i<=n;i++) {
      sum+=a[i];
      c[a[i]]++;
    }
    vector<int> ans;
    for (int i=1;i<=n;i++) {
      sum-=a[i];
      if (sum/2>200004) {
        sum+=a[i];
        continue;
      }
      if (sum/2!=a[i]&&sum%2==0&&c[sum/2]>=1) ans.pb(i);
      if (sum/2==a[i]&&sum%2==0&&c[sum/2]>1) ans.pb(i);
      sum+=a[i];
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
    return 0;
}

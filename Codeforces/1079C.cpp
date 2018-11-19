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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans[n+5];
    memset (ans,0,sizeof(ans));
    ans[0]=1;
    ans[1]=1;
    for (int i=2;i<=n;i++) {
      if (a[i]>a[i-1]) ans[i]=ans[i-1]+1;
      else if (a[i]<a[i-1]) ans[i]=ans[i-1]-1;
      else ans[i]=ans[i-1];
    }
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << endl;
    int rans[n+5];
    memset (rans,0,sizeof(rans));
    bool same=0;
    for (int i=1;i<=n;i++) {
      if (ans[i]==ans[i+1]) same=1;
      else same=0;
      if (!same) rans[i]=rans[i-1]+ans[i]-ans[i-1];
    }
    for (int i=1;i<=n;i++) cout << rans[i] << " ";
    return 0;
}

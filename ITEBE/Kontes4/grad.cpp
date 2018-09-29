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
    int a[5005];
    int cnt=0;
    for (int i=1;i<=n;i++) {
      cin >> a[i];
      if (a[i]>0) cnt++;
    }
    a[n+1]=0;
    bool y=1;
    int ans=0;
    while (1>0) {
      if (!y) break;
      y=0;
      int s=1,e=1;
      for (int i=s;i<=n;i++) {
        if (a[i]==0) s++;
        if (a[i+1]==0&&a[i]>0) {
          e=i;
          int mini=INT_MAX;
          for (int j=s;j<=e;j++) mini=min(mini,a[j]);
          if (e-s+1<mini) {
            for (int j=s;j<=e;j++) a[j]=0;
            ans+=e-s+1;
          } else {
            for (int j=s;j<=e;j++) a[j]-=mini;
            ans+=mini;
          }
          s=e+1;
          i=s;
          if (s>n) break;
        }
      }
      for (int i=1;i<=n;i++) {
        if (a[i]>0) y=1;
        //cout << a[i] << " ";
      }
      //cout << endl;
    }
    cout << ans << endl;
    return 0;
}

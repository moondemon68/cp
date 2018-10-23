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
    freopen ("A-small-attempt1.in","r",stdin);
    freopen ("A-small-attempt2.out","w",stdout);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      int n;
      cin >> n;
      LL a[205];
      map<LL,int> m;
      for (int i=1;i<=n;i++) {
        cin >> a[i];
        m[a[i]]++;
      }
      int ans=0;
      for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
          if (a[i]==1&&a[j]==1&&m[1]>2) ans+=m[1]-2;
          else if (a[i]==1&&m[j]>1) ans+=m[j]-1;
          else if (a[j]==1&&m[i]>1) ans+=m[i]-1;
          else if (a[i]==0&&a[j]==0&&m[0]>2) ans+=m[0]-2;
          else if ((a[i]==0||a[j]==0)&&m[0]>1) ans+=m[0]-1;
          else if (m[a[i]*a[j]]>0) ans+=m[a[i]*a[j]];
        }
      }
      printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

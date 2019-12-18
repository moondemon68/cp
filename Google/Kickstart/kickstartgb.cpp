#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
LL x[400005],y[400005],z[12],l[400005],r[400005],k;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("B-small-attempt0.in","r",stdin);
    freopen ("B-small-attempt0.out","w",stdout);
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      int n,q;
      cin >> n >> q;
      int a,b,c,m;
      cin >> x[1] >> x[2] >> a >> b >> c >> m;
      for (int i=3;i<=n;i++) {
        x[i]=a*x[i-1];
        x[i]%=m;
        x[i]+=b*x[i-2];
        x[i]%=m;
        x[i]+=c;
        x[i]%=m;
      }
      cin >> y[1] >> y[2] >> a >> b >> c >> m;
      for (int i=3;i<=n;i++) {
        y[i]=a*y[i-1];
        y[i]%=m;
        y[i]+=b*y[i-2];
        y[i]%=m;
        y[i]+=c;
        y[i]%=m;
      }
      cin >> z[1] >> z[2] >> a >> b >> c >> m;
      /*
      for (int i=1;i<=n;i++) cout << x[i] << " ";
      cout << endl;
      for (int i=1;i<=n;i++) cout << y[i] << " ";
      cout << endl;
      for (int i=1;i<=q;i++) cout << z[i] << " ";
      cout << endl;
      */
      LL maxi=0;
      for (int i=1;i<=n;i++) {
        l[i]=min(x[i],y[i])+1;
        r[i]=max(x[i],y[i])+1;
        maxi=max(maxi,r[i]);
      }
      k=z[1]+1;
      /*
      for (int i=1;i<=n;i++) cout << l[i] << " ";
      cout << endl;
      for (int i=1;i<=n;i++) cout << r[i] << " ";
      cout << endl;
      cout << k << endl;
      cout << endl;
      */
      map<int,int> g;
      for (int i=1;i<=n;i++) {
        for (int j=l[i];j<=r[i];j++) g[j]++;
      }
      int ans=0;
      for (int i=maxi;i>=1;i--) {
        k-=g[i];
        if (k<=0) {
          ans=i;
          break;
        }
      }
      printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

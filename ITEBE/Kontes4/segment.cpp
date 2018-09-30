#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,b,c;
    cin >> n >> b >> c;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    int l=1,r=2,ans=0,s=0;
    if (c==0) for (int i=1;i<=n;i++) if (a[i]%b!=0) ans++;
    if (c==1) for (int i=1;i<=n;i++) if (a[i]%b==0) ans++;
    while (l<=n&&r<=n) {
      if (l==r) r++;
      int d=a[r]/b-a[l]/b;
      if (a[l]%b==0) d++;
      cerr << "* " << a[l] << " " << a[r] << " " << d << endl;
      if (d==c) {
        s++;
        r++;
      } else if (d>c) {
        ans+=s*(s+1)/2;
        l++;
        s=0;
      } else {
        r++;
      }
    }
    ans+=s*(s+1)/2;
    cout << ans << endl;
    return 0;
}

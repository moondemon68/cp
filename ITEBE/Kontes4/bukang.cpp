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
    int m;
    cin >> n >> m;
    int a[40];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) a[i]%=m;
    vector<int> p,q;
    LL g=pow(2,n/2);
    for (LL i=1;i<g;i++) {
      int cnt=0;
      int x=0;
      LL r=i;
      while (r>0) {
        cnt++;
        if (r%2==1) {
          x+=a[cnt];
          x%=m;
        }
        r/=2;
      }
      p.pb(x);
    }
    int ans=0;
    sort (p.begin(),p.end());
    //for (int i=0;i<p.size();i++) cout << p[i] << " ";
    //cout << endl;

    g=pow(2,n-n/2);
    for (LL i=1;i<g;i++) {
      int cnt=n/2;
      int x=0;
      LL r=i;
      while (r>0) {
        cnt++;
        if (r%2==1) {
          x+=a[cnt];
          x%=m;
        }
        r/=2;
      }
      ans=max(ans,x%m);
      //cout << x << " ";
      int s=0,e=p.size()-1,num=0;
      while (s<=e) {
        int mid=(s+e)/2;
        if ((p[mid]+x)>=m) {
          e=mid-1;
        } else {
          num=p[mid]+x;
          s=mid+1;
        }
      }
      ans=max(ans,num);
    }
    cout << ans << endl;
    return 0;
}

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
    int n,k;
    cin >> n >> k;
    int a[100005];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    int l=0,h=INT_MAX,ans=0;
    while (l<=h) {
      int m=(l+h)/2;
      //cout << m << endl;
      int cnt=1,last=a[1];
      //cout << last << " ";
      for (int i=2;i<=n;i++) {
        if (a[i]-last>=m) {
          cnt++;
          last=a[i];
          //cout << last << " ";
        }
      }
      //cout << endl;
      if (k<=cnt) {
        ans=m;
        l=m+1;
      } else {
        h=m-1;
      }
    }
    cout << ans << endl;
    return 0;
}

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
    int a[1005];
    for (int i=1;i<=n;i++) cin >> a[i];
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
      int x;
      cin >>x;
      int l=1,h=1000000000,ans=0;
      while (l<=h) {
        int m=(l+h)/2,cnt=0;
        for (int j=1;j<=n;j++) {
          cnt+=a[j]/m+1;
        }
        if (cnt>x) {
          h=m-1;
        } else if (cnt<x) {
          l=m+1;
        } else {
          ans=m;
          l=m+1;
        }
      }
      cout << ans << endl;
    }
    return 0;
}

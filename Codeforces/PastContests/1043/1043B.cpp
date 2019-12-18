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
    a[0]=0;
    int x[1005];
    for (int i=1;i<=n;i++) {
      x[i]=a[i]-a[i-1];
      //cout << x[i] << " ";
    }
    //cout << endl;
    queue<int> ans;
    for (int i=1;i<=n;i++) {
      x[0]=x[i];
      bool y=1;
      for (int j=1;j<=n;j++) {
        if (x[j]!=x[j%i]) {
          //cout << i << " " << j << " " << j%i << endl;
          y=0;
          break;
        }
      }
      if (y) ans.push(i);
    }
    cout << ans.size() << endl;
    while (!ans.empty()) {
      cout << ans.front() << " ";
      ans.pop();
    }
    return 0;
}

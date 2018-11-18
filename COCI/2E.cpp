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
    int x1[10005],y1[10005],x2[10005],y2[10005];
    for (int i=1;i<=n;i++) {
      int x,y,a,b;
      cin >> x >> y >> a >> b;
      x1[i]=x;
      x2[i]=x+a;
      y1[i]=y;
      y2[i]=y+b;
    }
    bool ans=0;
    for (int i=1;i<=n;i++) {
      for (int j=i+1;j<=n;j++){
        if (x2[i]>x1[j]||x2[i]>x1[j]||y2[i]>y1[j]||y2[i]>y1[j]) {
          ans=1;
          break;
        }
      }
      if (ans) cout << "DA" << endl;
      else cout << "NE" << endl;
    }
    return 0;
}

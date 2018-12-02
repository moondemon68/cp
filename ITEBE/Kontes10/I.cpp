#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int bit[1030][1030],a[1030][1030];
int n;

void update(int x,int y,int val) {
  for (int i=x;i<=n;i+=i&-i) {
    for (int j=y;j<=n;j+=j&-j) {
      bit[i][j]+=val;
    }
  }
}

int get(int x,int y) {
  int ans=0;
  for (int i=x;i>0;i-=i&-i) {
    for (int j=y;j>0;j-=j&-j) {
      ans+=bit[i][j];
    }
  }
  return ans;
}

int query(int x1,int y1,int x2,int y2) {
  return get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
      cin >> n;
      memset (bit,0,sizeof(bit));
      memset (a,0,sizeof(a));
      string s;
      while (cin >> s) {
        if (s=="END") break;
        if (s=="SET") {
          int x,y,val;
          cin >> x >> y >> val;
          int diff=val-a[x+1][y+1];
          a[x+1][y+1]=val;
          update(x+1,y+1,diff);
        }
        if (s=="SUM") {
          int x1,y1,x2,y2;
          cin >> x1 >> y1 >> x2 >> y2;
          cout << query(x1+1,y1+1,x2+1,y2+1) << "\n";
        }
        /*for (int i=1;i<=n;i++) {
          for (int j=1;j<=n;j++) {
            cout << bit[i][j]<< " ";
          }
          cout << endl;
        }*/
      }
      cout << "\n";
    }
    return 0;
}

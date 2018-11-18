#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bool a[150][150];

vector<string> ans;

void code(int x1,int y1,int x2, int y2,string s) {
  bool y=1;
  for (int i=x1;i<=x2;i++) {
    for (int j=y1;j<=y2;j++) {
      if (a[i][j]!=a[x1][y1]) y=0;
    }
  }
  if (y&&a[x1][y1]) ans.pb(s);
  else if (y&&!a[x1][y1]) return;
  else {
    code(x1,y1,x1+(x2-x1)/2,y1+(y2-y1)/2,s+'0');
    code(x1+(x2-x1+1)/2,y1,x2,y1+(y2-y1)/2,s+'2');
    code(x1,(y2-y1+1)/2+y1,x1+(x2-x1)/2,y2,s+'1');
    code((x2-x1+1)/2+x1,(y2-y1+1)/2+y1,x2,y2,s+'3');
  }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset (a,0,sizeof(a));
    int r,c;
    cin >> r >> c;
    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) {
          cin >> a[i][j];
      }
    }
    int l=max(r,c);
    int p=pow(2,ceil(log2(l)));
    code(1,1,p,p,"1");
    sort (ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << endl;
    return 0;
}

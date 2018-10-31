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
    int t=0;
    while (1>0) {
      t++;
      int n;
      cin >> n;
      if (n==0) return 0;
      int a[100005][3];
      memset (a,0,sizeof(a));
      for (int i=0;i<n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
      a[0][2]+=a[0][1];
      a[1][0]+=a[0][1];
      a[1][1]+=min(a[0][2],min(a[0][1],a[1][0]));
      a[1][2]+=min(a[0][2],min(a[0][1],a[1][1]));
      for (int i=2;i<n;i++) {
        a[i][0]+=min(a[i-1][0],a[i-1][1]);
        a[i][1]+=min(min(a[i-1][0],a[i-1][1]),min(a[i-1][2],a[i][0]));
        a[i][2]+=min(min(a[i-1][1],a[i-1][2]),a[i][1]);
      }
      cout << t << ". " << a[n-1][1] << endl;
    }
    return 0;
}

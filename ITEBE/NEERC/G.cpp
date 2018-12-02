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
    int tc;
    cin >> tc;
    while (tc--) {
      int k;
      cin >> k;
      int a[15],week=0;
      memset (a,0,sizeof(a));
      for (int i=1;i<=7;i++) {
        cin >> a[i];
        week+=a[i];
      }
      int ans=0;
      if (k>week) {
        ans+=7*(k/(week));
        k%=(week);
      }
      if (k==0) {
        ans-=7;
        k=week;
      }
      //cout << endl;
      int mind=100;
      for (int i=1;i<=7;i++) {
        int plus=0,p=i,cnt=0,kk=k;
        while (kk>0) {
          cnt++;
          if (a[p]==1) {
            kk--;
          }
          p++;
          if (p>7) p-=7;
        }
        mind=min(mind,cnt);
      }
      //cout << mind << endl;
      cout << ans+mind << endl;
    }
    return 0;
}
/*
5
2
0 1 0 0 0 0 0
100000000
1 0 0 0 1 0 1
1
1 0 0 0 0 0 0
5
1 0 0 1 0 1 0
4
1 0 0 0 0 0 1
*/

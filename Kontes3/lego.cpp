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
    int tc;
    scanf("%d",&tc);
    for (int t=1;t<=tc;t++) {
      LL x1,y1,x2,y2,k;
      scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&k);
      //cin >> x1 >> y1 >> x2 >> y2 >> k;
      LL x=(x2-x1);
      LL y=(y2-y1);
      if (x<y) swap(x,y);
      if ((x%2==0&&y%2==1)||(x%2==1&&y%2==0)) {
        k--; x--;
      }
      else if ((x%2==0&&k%2==1)||(x%2==1&&k%2==0)) {
        x--; y--;k-=2;
      }
      if (k<x) printf("-1\n");
      else printf("%lld\n",k);
    }
    return 0;
}

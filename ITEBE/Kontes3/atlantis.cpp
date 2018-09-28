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
    /*
    for (int t=1;t<=15;t++) {
      set<int> ans;
      for (int i=0;i<=pow(4,t);i++) {
        int x=i;
        int p=0,cnt=0;
        while (x>0) {
          cnt++;
          if (x%4==0) p+=1;
          else if (x%4==1) p+=5;
          else if (x%4==2) p+=10;
          else if (x%4==3) p+=50;
          x/=4;
        }
        while (cnt<=t) {
          cnt++;
          p++;
        }
        ans.insert(p);
      }
      cout << ans.size() << endl;
    }
    */

    int ans[12]={0,4,10,20,35,56,83,116,155,198,244,292};
    for (int t=1;t<=tc;t++) {
      LL x;
      scanf("%lld",&x);
      if (x<=11) {
        printf("%d\n",ans[x]);
      } else printf("%lld\n",(x-11)*49+292);
    }

    return 0;
}

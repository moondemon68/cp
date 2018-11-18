#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL BIT[18000005],a[5000005],n;

void update(int x,int d) {
  for (; x<=n;x+=x&-x) {
    BIT[x]+=d;
  }
}

LL query(int x) {
  LL sum=0;
  for (; x>0;x-=x&-x) {
    sum+=BIT[x];
  }
  return sum;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=q;i++) {
      char x;
      scanf(" %c",&x);
      if (x=='+') {
        int y,z;
        scanf("%d%d",&y,&z);
        update(y+1,z);
      } else {
        int y;
        scanf("%d",&y);
        printf("%lld\n",query(y));
      }
    }
    return 0;
}

#include <bits/stdc++.h>
#define le first
#define fi second.first
#define se second.second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int main () {
    LL n,m;
    int q;
    cin >> m >> n >> q;
    priority_queue< pair<LL,pair<LL,LL> > > p,l;
    p.push(mp(n,mp(1,n)));
    l.push(mp(m,mp(1,m)));
    map<LL,bool> pp,ll;
    pp[1]=1;
    pp[n]=1;
    ll[1]=1;
    ll[m]=1;
    for (int t=1;t<=q;t++) {
      int type;
      cin >> type;
      LL x;
      cin >> x;
      if (type==1) {
        if (x>=p.top().fi&&x<=p.top().se) {
          LL r=p.top().fi,s=p.top().se;
          p.pop();
          p.push(mp(x-r,mp(r,x)));
          p.push(mp(s-x,mp(x,s)));
          pp[x]=1;
        } else {
          pp[x]=1;
        }
      } else {
        if (x>=l.top().fi&&x<=l.top().se) {
          LL r=l.top().fi,s=l.top().se;
          l.pop();
          l.push(mp(x-r,mp(r,x)));
          l.push(mp(s-x,mp(x,s)));
          ll[x]=1;
        } else {
          ll[x]=1;
        }
      }
      cout << p.top().le*l.top().le << endl;
    }
    return 0;
}

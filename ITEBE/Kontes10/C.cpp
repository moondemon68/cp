#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL a[200005],p[200005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,size;
    cin >> n;
    size=n;
    for (LL i=1;i<=n;i++) cin >> a[i];
    reverse(a+1,a+n+1);
    memset (p,0,sizeof(p));
    for (LL i=1;i<=n;i++) p[i]=p[i-1]+a[i];
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
      int t;
      cin >> t;
      if (t==1) {
        LL x,y;
        cin >> x >> y;
        //for (int g=1;g<=size;g++) cout << p[g] << " ";
        //cout << endl;
        cout << p[size-x+1]-p[size-y] << endl;
      } else {
        size++;
        LL x;
        cin >> x;
        a[size]=x;
        p[size]=p[size-1]+x;
      }
    }
    return 0;
}

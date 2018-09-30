#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[300005],b[300005];
bool eq(int al,int ar,int bl,int br) {
    //cerr << "* "<< al << ar << bl << br << endl;
    if ((ar-al)!=(br-bl)) return 0;
    if (ar==al) {
      //cerr<< a[ar] << b[br] << endl;
      return a[ar]==b[br];
    }
    bool y=1;
    int cnt=0,siz=ar-al;
    while (cnt<=siz) {
      //cerr << a[al+cnt] << b[bl+cnt] << " ";;
      if (a[al+cnt]!=b[bl+cnt]) {
        y=0;
        break;
      }
      cnt++;
    }
    //cerr << endl;
    if (y) return 1;
    if ((eq(al,al+(ar-al)/2,bl,bl+(br-bl)/2)&&eq(al+(ar-al)/2+1,ar,bl+(br-bl)/2+1,br))||
    (eq(al,al+(ar-al)/2,bl+(br-bl)/2+1,br)&&eq(al+(ar-al)/2+1,ar,bl,bl+(br-bl)/2))) return 1;
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    if (eq(1,n,1,n)) cout << "EQ"; else cout << "NEQ";
    return 0;
}

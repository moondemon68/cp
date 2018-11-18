#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL tree[18000005],a[5000005],n;

void update(int node,int start,int end,int idx,int d) {
  if (start==end) {
    a[idx]+=d;
    tree[node]+=d;
  } else {
    int mid=(start+end)/2;
    if (start<=idx&&idx<=mid) update(2*node,start,mid,idx,d);
    else update(2*node+1,mid+1,end,idx,d);
    tree[node]=tree[2*node]+tree[2*node+1];
  }
}

LL query(int node,int start,int end,int l,int r) {
  if (l<=start&&end<=r) {
    return tree[node];
  }
  if (r<start||end<l) {
    return 0;
  }
  int mid=(start+end)/2;
  return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> n >> q;
    memset (a,0,sizeof(a));
    for (int i=1;i<=q;i++) {
      char x;
      cin >> x;
      if (x=='+') {
        int y,z;
        cin >> y >> z;
        update(1,1,n,y+1,z);
      } else {
        int y;
        cin >> y;
        cout << query(1,1,n,1,y) << "\n";
      }
    }
    return 0;
}

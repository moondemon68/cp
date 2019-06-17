#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int tree[3000005],a[1000005],n,k;

void build(int node,int start,int end) {
  if (start==end) {
    tree[node]=a[start];
  } else {
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=min(tree[2*node],tree[2*node+1]);
  }
}

void update(int node,int start,int end,int idx,int val) {
  if (start==end) {
    a[idx]=val;
    tree[node]=val;
  } else {
    int mid=(start+end)/2;
    if (start<=idx&&idx<=mid) {
      update(2*node,start,mid,idx,val);
    } else {
      update(2*node+1,mid+1,end,idx,val);
    }
    tree[node]=min(tree[2*node],tree[2*node+1]);
  }
}

int query(int node,int start,int end,int l,int r) {
  if (r<start||end<l) {
    return MOD;
  }
  if (l<=start&&end<=r) {
    return tree[node];
  }
  int mid=(start+end)/2;
  int p1=query(2*node,start,mid,l,r);
  int p2=query(2*node+1,mid+1,end,l,r);
  return min(p1,p2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset (a,0,sizeof(a));
    for (int i=1;i<=3000000;i++) tree[i]=MOD;
    cin >> n>> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    build (1,1,n);
    for (int i=1;i<=k;i++) {
      char t;
      cin >> t;
      if (t=='u') {
        int x,y;
        cin >> x >> y;
        update(1,1,n,x,y);  //updates x-th element to y
      } else {
        int x,y;
        cin >> x >> y;
        cout << query(1,1,n,x,y) << endl;   //outputs smallest element in range x-y
      }
    }
    //for (int i=1;i<=n;i++) cout << a[i] << " ";
    return 0;
}

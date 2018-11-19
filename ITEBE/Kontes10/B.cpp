#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int tree[400005],a[200005],n;

void build (int node,int start,int end,int level) {
  if (start==end) {
    tree[node]=a[start];
  } else {
    int mid=(start+end)/2;
    build (2*node,start,mid,level+1);
    build (2*node+1,mid+1,end,level+1);
    if ((n-level)%2==0) tree[node]=tree[2*node]|tree[2*node+1];
    else tree[node]=tree[2*node]^tree[2*node+1];
  }
}

void update (int node,int start,int end,int idx,int val,int level) {
  if (start==end) {
    tree[node]=val;
  } else {
    int mid=(start+end)/2;
    if (start<=idx&&idx<=mid) {
      update(2*node,start,mid,idx,val,level+1);
    } else {
      update(2*node+1,mid+1,end,idx,val,level+1);
    }
    if ((n-level)%2==0) tree[node]=tree[2*node]|tree[2*node+1];
    else tree[node]=tree[2*node]^tree[2*node+1];
  }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset (tree,0,sizeof(tree));
    memset (a,0,sizeof(a));
    int q;
    cin >> n >> q;
    int k=pow(2,n);
    for (int i=1;i<=k;i++) cin >> a[i];
    build (1,1,k,1);
    //for (int i=1;i<=10;i++) cout << tree[i] << " ";
    //cout << endl;
    for (int i=1;i<=q;i++) {
      int x,y;
      cin >> x >> y;
      update(1,1,k,x,y,1);
      cout << tree[1] << endl;
    }
    return 0;
}

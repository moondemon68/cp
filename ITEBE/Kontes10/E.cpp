#include <bits/stdc++.h>
#define pre first.first
#define suf first.second
#define maxsum second.first
#define sum second.second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[50005];
pair<pii,pii> tree[200005];

void build (int node,int start,int end) {
  if (start==end) {
    tree[node].sum=a[start];
    tree[node].pre=a[start];
    tree[node].suf=a[start];
    tree[node].maxsum=a[start];
  } else {
    int mid=(start+end)/2;
    build (2*node,start,mid);
    build (2*node+1,mid+1,end);
    tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
    tree[node].pre=max(tree[2*node].pre,tree[2*node+1].pre+tree[2*node].sum);
    tree[node].suf=max(tree[2*node+1].suf,tree[2*node].suf+tree[2*node+1].sum);
    tree[node].maxsum=max(max(tree[node].pre,tree[node].suf),max(tree[2*node].suf+tree[2*node+1].pre,max(tree[2*node].maxsum,tree[2*node+1].maxsum)));
  }
}

int query(int node,int start,int end,int l,int r) {
  if (l<=start&&end<=r) {
    return tree[node].maxsum;
  }
  if (r<start||end<l) {
    return -MOD*2;
  }
  int mid=(start+end)/2;
  return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset (a,0,sizeof(a));
    memset (tree,0,sizeof(tree));
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    build (1,1,n);
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
      int x,y;
      cin >> x >> y;
      cout << query(1,1,n,x,y) << endl;
    }
    return 0;
}

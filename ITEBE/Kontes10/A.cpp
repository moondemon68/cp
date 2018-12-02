#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[400005],tree[400005],n,last[1000005],ans[400005];
pair<pii,int> queries[200005];

bool cmp(pair<pii,int> a,pair<pii,int> b) {
  return a.fi.se<b.fi.se;
}

void update(int x,int d) {
  for (int i=x;i<=n;i+=(i&-i)) {
    tree[i]+=d;
  }
}

int query(int x) {
  int ans=0;
  for (int i=x;i>0;i-=(i&-i)) {
    ans+=tree[i];
  }
  return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(a,0,sizeof(a));
    memset (tree,0,sizeof(tree));
    memset (last,0,sizeof(last));
    memset (queries,0,sizeof(queries));
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
      cin >> queries[i].fi.fi >> queries[i].fi.se;
      queries[i].se=i;
    }
    sort (queries+1,queries+q+1,cmp);
    int cnt=1;
    for (int i=1;i<=n;i++) {
      if (last[a[i]]!=0) {
        update(last[a[i]],-1);
      }
      update(i,1);
      last[a[i]]=i;
      //for (int j=1;j<=n;j++) cout << tree[j] <<  " ";
      //cout << endl;
      while (queries[cnt].fi.se==i) {
        ans[queries[cnt].se]=query(queries[cnt].fi.se)-query(queries[cnt].fi.fi-1);
        //cout << queries[cnt].fi.se << " " << queries[cnt].fi.fi-1 <<" "<< ans[queries[cnt].se] << endl;
        cnt++;
      }
    }
    for (int i=1;i<=q;i++) {
      cout << ans[i] << "\n";
    }
    return 0;
}

/*
5
1 1 2 1 3
3
1 5
2 4
3 5
*/

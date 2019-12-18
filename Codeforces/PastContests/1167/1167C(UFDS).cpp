#include <bits/stdc++.h>
#define el '\n'
using namespace std;

int par[500005], sz[500005];

int find(int x){
  return par[x]==x ? x : par[x]=find(par[x]);
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(sz[y] > sz[x]) swap(x,y);
  par[y] = x;
  sz[x] += sz[y];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    par[i] = i;
    sz[i] = 1;
  }

  for(int i = 0; i < m; i++){
    int q; cin >> q;
    int first;
    for(int j = 0; j < q; j++){
      int u;
      cin >> u;
      if(j==0) first = u;
      else unite(first, u);
    }
  }

  for(int i = 0; i < n; i++){
    cout << sz[find(i+1)] << ' ';
  }
  return 0;
}
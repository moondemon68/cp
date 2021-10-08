#include "paint.h"

#include <bits/stdc++.h>

using namespace std;

int minimumInstructions(int N, int M, int K, std::vector<int> C, std::vector<int> A, std::vector<std::vector<int>> B) {
  int s[K];
  memset (s,-1,sizeof(s));
  for (int i=0;i<M;i++) {
    for (int j=0;j<A[i];j++) {
      s[B[i][j]] = (i);
    }
  }

  vector<int> v;
  for (int y=0;y<=N-M;y++) {
    if (s[C[y]] == (-1)) continue;
    for (int x=(s[C[y]]);x<=(s[C[y]]);x++) {
      bool can = 1;
      for (int l=0;l<M;l++) {
        if (s[C[y+l]] != ((x+l)%M)) {
          can = 0;
          y += l-1;
          break;
        }
      }
      if (can) {
        v.push_back(y);
        y += M-1;
        break;
      }
    }
  }

  // for (auto x : v) cout << x << " ";
  // cout << endl;

  if (v.empty() || v[0] != 0) {
    return -1;
  }
  
  if (v[0] == 0 && N-M == 0) {
    return 1;
  }

  int ans = 1, last = 0;
  for (int i=0;i<v.size();i++) {
    int ada = -1;
    // cout << last << endl;
    for (int j=i;j<v.size();j++) {
      if (v[j] > last+M) break;
      else {
        ada = j;
      }
    }
    if (ada == -1 || last == v[ada]) {
      return -1;
    }
    i = ada-1;
    ans++;
    last = v[ada];
    if (last == N-M) return ans;
  }
  return -1;

  // return ans;
}

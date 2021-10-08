#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];

void init(int N, int M, vector<int> U, vector<int> V, vector<int> W) {
  for (int i=0;i<M;i++) {
    adj[U[i]].push_back(V[i])
  }
}

int getMinimumFuelCapacity(int X, int Y) {
  return -1;
}

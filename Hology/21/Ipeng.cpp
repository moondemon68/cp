#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int N = 1e2 + 5;
int n, m;

bool ok(int i, int j) { return i >= 1 && i <= n && j >= 1 && j <= m; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> grid(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (grid[i][j] == 0) {
        continue;
      }

      queue<queue<pair<pii, int>>> q;  // per layer
      queue<pair<pii, int>> tmp;

      vector<vector<int>> curgrid = grid;
      tmp.push({{i, j}, curgrid[i][j]});
      q.push(tmp);
      curgrid[i][j] = 0;
      vector<vector<pii>> delta(n + 1, vector<pii>(m + 1));
      int cur = 0;
      while (!q.empty()) {
        queue<pair<pii, int>> iq = q.front();
        q.pop();

        queue<pair<pii, int>> nextLayer;

        while (!iq.empty()) {
          pair<pii, int> fr = iq.front();
          iq.pop();
          cur++;

          pii pos = fr.fi;
          int power = fr.se;

          pii prev = pos;
          pos = {pos.fi + delta[pos.fi][pos.se].fi,
                 pos.se + delta[pos.fi][pos.se].se};
          delta[prev.fi][prev.se] = {0, 0};
          // cout << pos.fi << ' ' << pos.se << "|";

          if (pos.fi < 0) pos.fi = 1;
          if (pos.fi > n) pos.fi = n;
          if (pos.se < 0) pos.se = 1;
          if (pos.se > m) pos.se = m;

          for (int dr = -power; dr <= power; dr++) {
            if (dr == 0) {
              continue;
            }
            int dc = 0;
            int ni = pos.fi + dr, nj = pos.se + dc;
            if (!ok(ni, nj)) {
              continue;
            }
            if (curgrid[ni][nj] == 0) {
              continue;
            }

            int posr = dr, posc = dc;
            if (posr != 0) {
              posr /= abs(posr);
            }
            if (posc != 0) {
              posc /= abs(posc);
            }

            nextLayer.push({{ni, nj}, curgrid[ni][nj]});
            curgrid[ni][nj] = 0;
            delta[ni][nj].fi += posr;
            delta[ni][nj].se += posc;
          }
          for (int dc = -power; dc <= power; dc++) {
            if (dc == 0) {
              continue;
            }
            int dr = 0;
            int ni = pos.fi + dr, nj = pos.se + dc;
            if (!ok(ni, nj)) {
              continue;
            }
            if (curgrid[ni][nj] == 0) {
              continue;
            }

            int posr = dr, posc = dc;
            if (posr != 0) {
              posr /= abs(posr);
            }
            if (posc != 0) {
              posc /= abs(posc);
            }

            nextLayer.push({{ni, nj}, curgrid[ni][nj]});
            curgrid[ni][nj] = 0;
            delta[ni][nj].fi += posr;
            delta[ni][nj].se += posc;
          }
        }
        // cout << " - ";
        if (!nextLayer.empty()) {
          q.push(nextLayer);
        }
      }
      // cout << '\n';
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
  return 0;
}